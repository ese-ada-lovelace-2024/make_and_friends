# Using a shell script to build code

A halfhearted attempt to automate the build process is to put the commands in a text file. Here we have one for building on a Linux/macOS system and one for Windows.

This is hard to maintain and doesn't scale well, but it's a start.

On linux/macOS, you should be able to run the following command to build the code:

```bash

./compile.sh
```
This will run the script `compile.sh` in the current directory. You may need to make it executable first with the command:

```bash
chmod u+x compile.sh
```
This will make the script executable by the user. You only need to do this once. After that, you can run it as many times as you like.

On Windows, you can run the following command to build the code:

```bash
.\compile.bat
```

This will only work if the C compiler is in your PATH. The easiest way to do this is to use one of the Tools Command Prompt sessions that come with Visual Studio. You can find these in the Start menu under Visual Studio. Look for something like "Developer Command Prompt for VS 2024" or "x64 Native Tools Command Prompt for VS 2024". This will set up the environment variables for you.