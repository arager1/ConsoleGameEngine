# HeadlessGameEngine

Note: Don't follow RebuildAndRun.sh


### Component Status:

##### Stable Components:
N/A ;)

##### Components which have ever been tested:
Engine/Main/
Engine/Core/

##### Actively-building Components:
Engine/StateMachine/
Mathematic/
RandomDistribution/CatagoricalDistribution

##### Mostly just ideas:
RandomDistribution/UUID-Gen
Serial/
UserInterface


### To Build:

From root directory:

1. (Init)
if "Build" directory doesn't exist:
```
mkdir Build
cd Build
```

2. (CMake Configure + Generate)
if Engine-Only build (no game to build, testing engine)
```
cmake .. -DENGINE_ONLY_MODE:BOOL=True
```
else (building with a real game)
```
cmake ..
```

Optional enable game-log (with CMake cmd):
```
-DLOGGING_ENABLED:BOOL=True
```

3. (Compile)
```
make
```

4. (Run)
```
./bin/Game
```
