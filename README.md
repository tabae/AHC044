# Solving [AHC044](https://atcoder.jp/contests/ahc044/tasks/ahc044_a)

This repository is a simple C++ project template for AtCoder Heuristic Contest.

## Download and setup
Download this project.
```bash
wget https://github.com/tabae/ahc-template-project/archive/refs/heads/main.zip
```

Expand it and rename the directory.
```
unzip main.zip
rm  main.zip
mv ahc-template-project-main ahcXXX
```

If you use [pacher](https://github.com/terry-u16/pahcer), run init command.
For example:
```
cd ahcXXX
pahcer init -p ahcXXX -o max -l cpp
sed -i "s/main.cpp/src\/main.cpp/" pahcer_config.toml
```

## Expander

Before submitting your solution, combine them into a single file.

```
python expander.py --lib src/ src/main.cpp
```
