# HeadlessGameEngine

Note: Don't follow RebuildAndRun.sh


### Component Status:

##### Stable Components:
N/A ;)  

##### Components which have ever been tested:
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

Optional enable game-log with path to log file (relative to Build folder):
```
-DLOG_FILE:FILEPATH=/HeadlessGame.log
```

Optional enable debug symbols for debugger:
```
-DCMAKE_BUILD_TYPE=Debug
```
Example with multiple flags:  
This will build "Engine Only", enable Game logging to RepoRoot/Build/HeadlessGame.log, and enable debugging
```
cmake .. -DENGINE_ONLY_MODE:BOOL=True -DLOG_FILE:FILEPATH=/HeadlessGame.log -DCMAKE_BUILD_TYPE=Debug
```

3. (Compile)  
```
make
```

4. (Run)  
```
./bin/Game
```
