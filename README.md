- Install cmake
- Basic build using cmake
```bash
mkdir build
cd build
cmake -G "Unix Makefiles" ../source # skip -G to use default generator
cmake --build . --config Release --target MyApp
```
- build folder contains project files and generally kept separate from project src dir, maybe as a sibling
