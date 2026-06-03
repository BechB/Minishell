How to use: 
make / make re
./minishell

What you build
A command-line interpreter that:

Displays a prompt and waits for user input
Has a working history (navigable with arrow keys)
Finds and launches executables via PATH, or via relative/absolute paths
Handles redirections: <, >, << (heredoc), >>
Handles pipes | — chaining commands via fork + pipe
Handles environment variables ($VAR, $?)
Handles quotes — single ' (no expansion) and double " (with expansion)
Implements a set of built-in commands without calling external binaries


Required built-ins
CommandRoleechowith -n flagcdwith relative/absolute pathpwdprint working directoryexportset env variablesunsetremove env variablesenvprint environmentexitexit the shell

Key technical challenges
Lexer / Parser — tokenizing raw input into commands, arguments, pipes, and redirections. Getting quote handling and edge cases right is notoriously hard.
AST or command table — structuring parsed tokens into an executable representation.
Execution — fork(), execve(), managing file descriptors for pipes and redirections, waiting for child processes.
Signal handling — Ctrl+C (SIGINT), Ctrl+D (EOF), Ctrl+\ (SIGQUIT) must behave like Bash.
Heredoc (<<) — collecting input until a delimiter, then piping it to the command.
Memory management — the entire project must be leak-free (except for readline's known leaks).

Common pitfalls

Pipes with multiple commands (e.g. cmd1 | cmd2 | cmd3) require careful fd management to avoid leaks or deadlocks
$? must reflect the exit status of the last executed command
Built-ins run in the parent process (not forked), unlike external commands
Edge cases in quote parsing ("hello'world", empty strings, etc.)
