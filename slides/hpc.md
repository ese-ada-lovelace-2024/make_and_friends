# DUG & HPC

acse2020.github.io/acse-6-make/slides/hpc.html

j.percival@imperial.ac.uk



## ssh to DUG on windows command line

- Bug in `ssh -J` in prompt/powershell on windows:

    - Can use other client (e.g. MobaXTerm)
    - Can use Windows bash
    - Can use longer command:
    ```
    ssh -o ProxyCommand="C:\Windows\System32\OpenSSH\ssh.exe -W %h:%p iclmsc_user000@perth.mccloud.dug.com" iclmsc_user000@mcc_iclmsc
    ```
    - last one also works in `.ssh\config` file.



### Key glossary

- node: A "computer" in the cluster
- cpu: A processor core inside a computer
- task: A process on a node
- job: script/command submitted to the schedule

Note that you get an entire machine, per node, even if you only use 1 core on it.



### Useful Modules

Add with `module add X`, remove with `module rm X` (or `module load/unload`)  

- `git`: Add in a git command (can only see GitHub from login node)
- `intel-composer`: Add in the intel compilers (eg. `icpc` for C++)
- `intel-mpi`: Intel alternative to mpi
- `python/3.7.3`: Add in python3