#!/usr/bin/env python3
import re
import subprocess
from collections import defaultdict, deque

def generate_mermaid():
    """Git Mermaid図を生成"""
    cmd = [
        'git', 'log', '--oneline', '--decorate', '--all',
        '--pretty=format:%h|%d|%s', '--reverse'
    ]
    result = subprocess.run(cmd, capture_output=True, text=True)
    
    mermaid = ["gitGraph"]
    current_branch = "main"
    created_branches = set(["main"])  # 作成済みブランチを追跡
    
    for line in result.stdout.strip().split('\n'):
        if not line.strip():
            continue
            
        parts = line.split('|')
        if len(parts) < 3:
            continue
            
        commit_hash, refs, message = parts
        
        # ブランチ検出
        branch_name = "main"
        if refs:
            # HEAD -> branch-name の形式を検出
            match = re.search(r'->\s*([^,\s)]+)', refs)
            if match:
                branch_name = match.group(1).replace('origin/', '')
            else:
                # カンマ区切りの最初のブランチ名を取得
                branches = re.findall(r'([^,\s(]+)(?=[,\s)]|$)', refs)
                for branch in branches:
                    if branch not in ['HEAD', 'tag:'] and '->' not in branch:
                        branch_name = branch.replace('origin/', '')
                        break
        
        # 不正な文字を除去
        branch_name = re.sub(r'[^\w\-]', '_', branch_name)
        
        # ブランチが変更された場合
        if branch_name != current_branch:
            # 新しいブランチがまだ作成されていない場合
            if branch_name not in created_branches:
                mermaid.append(f'    branch {branch_name}')
                created_branches.add(branch_name)
            
            mermaid.append(f'    checkout {branch_name}')
            current_branch = branch_name
        
        # タグ検出
        tag_match = re.search(r'tag:\s*([^,\s)]+)', refs)
        tag_str = f' tag: "{tag_match.group(1)}"' if tag_match else ''
        
        mermaid.append(f'    commit id: "{commit_hash}: {message}"{tag_str}')
    
    return '\n'.join(mermaid)

if __name__ == "__main__":
    try:
        result = generate_mermaid()
        print("生成されたMermaidコード:")
        print(result)
        
        # ファイルに保存
        with open('git_graph.mmd', 'w', encoding='utf-8') as f:
            f.write(result)
        print("\n✅ Mermaidファイルを 'correct_graph.mmd' に保存しました")
        
    except Exception as e:
        print(f"エラー: {e}")
        import traceback
        traceback.print_exc()
