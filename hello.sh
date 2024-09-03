#!/bin/bash


while getopts ":l:" opt; do
  case $opt in
    l)
      case $OPTARG in
        "en")
          echo "Hello World!"
          ;;
        "ja")
          echo "こんにちは、世界！"
          ;;
        "zh")
          echo "你好，世界！"
          ;;
        "ko")
          echo "안녕하세요, 세계!"
          ;;
        "ru")
          echo "Привет, мир!"
          ;;
        "tl")
          echo "Kamusta, mundo!"
          ;;
        "de")
          echo "Hallo Welt!"
          ;;
        "ar")
          echo "!مرحبًا بالعالم"
          ;;
        "hi")
          echo "नमस्ते दुनिया!"
          ;;
        *)
          echo "無効な言語オプション: $OPTARG" >&2
          exit 1
          ;;
      esac
      ;;
    ?)
      echo "Hello World!"
      ;;
  esac
done

