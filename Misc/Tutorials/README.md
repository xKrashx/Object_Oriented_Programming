# How to debug multiple C++ source files in VSCode

[Video tutorial](https://www.youtube.com/watch?v=DVyYnOHP4nY)

## In short:

### :warning: You must put all source files in the same directory for this to work

### :one: Launch the debugger from the main file. This will fail, but it will also create a `launch.json` or `tasks.json` file in the `.vscode` directory

### :two: Edit the config json file to include all source files: in the `args` section search for a line with something like `"${file}"` and replace it with `"${workspaceFolder}/*.cpp"` or simply `"*.cpp"`

