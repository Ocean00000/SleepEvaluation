# SleepEvaluation

Windows でスリープ関数の実際の待機時間（精度）を計測・評価する C++ プロジェクトです。

## 概要

スリープ関数は指定時間だけ処理を停止しますが、OS のスケジューラや割り込みタイマーの影響により、実際の待機時間は指定値より長くなることがあります。本プロジェクトでは各スリープ関数を 1ms 指定で繰り返し呼び出し、`std::chrono::steady_clock` で計測した平均実待機時間を CSV 形式で出力します。

## 計測対象

| スリープ関数 | API | 単位 |
|---|---|---|
| `std::this_thread::sleep_for` | C++ 標準 | ミリ秒 |
| `Sleep` | Windows API | ミリ秒 |

## プロジェクト構成

| ファイル | 説明 |
|---|---|
| `SleepEvaluation/SleepEvaluation.cpp` | エントリポイント。計測処理と結果出力を行う |
| `SleepEvaluation/FunctionSleep.hpp` | 各スリープ関数のラッパー定義 |
| `SleepEvaluation/SleepName.hpp` | スリープ関数の表示名を取得するユーティリティ |
| `SleepEvaluation/Unit.hpp` | 計測単位の表示名を取得するユーティリティ |

## 動作環境

- Windows
- Visual Studio（C++17 以上を想定）
- Windows SDK（`windows.h` を使用）

## ビルドと実行

1. `SleepEvaluation.sln` を Visual Studio で開きます。
2. ソリューションをビルドします。
3. 生成された実行ファイルを実行します。

実行すると、以下のような形式で結果が標準出力に出力されます。

```
Sleep,Resolution,Unit
<スリープ関数名>,<平均待機時間>,<単位>
```

## 注意事項

- 計測中はプロセスの優先度を `ABOVE_NORMAL_PRIORITY_CLASS` に引き上げ、計測後に `NORMAL_PRIORITY_CLASS` に戻します。これは計測精度を上げるための措置です。
- 本プロジェクトは Windows 固有の API に依存しているため、他プラットフォームでは動作しません。
