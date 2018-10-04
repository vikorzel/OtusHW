chcp 65001 
IF NOT exist "sln" (
  mkdir sln
)
cd sln
cmake .. -G "Visual Studio 15 2017"
