#!/bin/bash

language="en"  # デフォルトは英語

while getopts ":l:" opt; do
  case $opt in
    l)
      case $OPTARG in
        "en")
          language="en"
          ;;
        "ja")
          language="ja"
          ;;
        "zh")
          language="zh"
          ;;
        "ko")
          language="ko"
          ;;
        *)
          echo "Invalid language option: $OPTARG" >&2
          exit 1
          ;;
      esac
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

if [ "$language" == "en" ]; then
  echo "Hello World!"
elif [ "$language" == "ja" ]; then
  echo "こんにちは、世界！"
elif [ "$language" == "zh" ]; then
  echo "你好，世界！"
elif [ "$language" == "ko" ]; then
  echo "안녕하세요, 세계!"
else
  echo "Unsupported language: $language" >&2
  exit 1
fi

