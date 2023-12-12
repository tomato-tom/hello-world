#!/bin/bash

string="Hello World!"

for (( i=0; i<${#string}; i++ )); do
    echo -n "${string:$i:1}"
    sleep 0.1  # 0.1秒の遅延（必要に応じて調整）
done

echo  # 改行を追加

