# 42School-minishell
This program is a shell enviroment with simple functionalities.  

# structure  

The shell process is executed following three steps: lexing, parsing and execution; these steps are executed by the lexer, the parser and the exec respectivelly.  
for all its utilities the program utilizes a CFG (context-free grammar) and a pushdown automaton created to parse it.  

## CFG  

Defined as a 5-tuple:  
    &Sigma; =    {echo, ls, grep, sed, ...}  
    &Theta; =    {-}[A -Za - z]\*[0 - 9]\* U {--}([A - Za - z]\*{=, -})* 
    &xi;    =    {"}X[A -Za - z]X{"} U {'}X[A -Za - z]X{'}  
    &Psi;   =    {|}  
    &lambda;=    {<<,<,>,>>}  

Each element of the tuple contain a set of valid strings that are a part of it.  
The first element, the &Sigma; (Terminals), contain all strings that correspond to a single command that can be executed by the shell, those being, any builtin command, any command that can be accesed at the paths contained by the $PATH enviroment variable, and, aditionally, it contains all direct paths to any command. Any part of the input string that follows one of these rules can be classified as a terminal.  
The second element, the &Theta; (Flag), contain all strings that correspond to a flag for a command, those being, all strings that start with a '-' character followed by any combination of alphanumerical characters, or, a string starting in '--' followed by any combination of alphanumerical characters, or special characters like '-' and '='.  
The third elemenet, the &xi; (String), contain all strings that start and end with quotes or single quotes, and also, all remaining strings that can't be classified any other way.  
Aditionally, any &Sigma; that did not start at the very first position on the input, or right after a pipe is classified as a string.  
The fourth element, the &Psi;, contain the pipe simbol, and has special inplications for the parsing process, allowing the recurive loop for multiple commands.  
The fifth element, the &lambda; (Special), contain all strings that can be interpreted as a special symbol, like heredoc and append.  

## The Automaton;  

The automaton consists of several elements, the states of the automaton act as the modes of operation, it's a set of numbers, each relating to a single mode of operation, the automaton starts in its 'starting state' and wherever it stops operating (reach the end of the input string) it will either be in one of its accepting states or not, if not, the parsing has found an error in the input.  
The input alphabet of the automaton is a set of all possible inputs it can receive, while its stack alphabet is all possible itens that can exist in its stack, the stack will always start with the automaton's initial symbol on top of it. The stack is a auxiliar tool for the automaton, it allows it to check for its relations.  

The transitions of the automaton will define how it will act when finding a specfic combination of input and symbol on top of the stack.  

The language of the automaton is a structure containing all the values for the language to be parsed.  

The automaton works duo to a set of functions:  

- automaton_new:  
    this function will be responsible for the intial allocation of all parts of the automaton, it will give it all the tools needed for it to do its job.  

- automaton_states:  
    This function will fill the set of states of the automaton.  

- automaton_astates:  
    This function will fill the set of all accepting states of the automaton.  

- automaton_transition_relation:  
    This function will fill the set of all transition relations of the automaton.  

- automaton_act:  
    This function will give to the automaton the next token to be read as an input, then the automaton will analyse it against its relations, using the stack as a tool. It will return the action to take, and, also, change its pop and push its stack as needed. The return is FALSE_INDEX if the there is no action to be taken in the situation.  

- automaton_find_transition:  
    This function will loop all the possible transitions the automaton can make, and, when a valid transition is found, return its value, otherwise, if no transition is valid in the situation, FALSE_INDEX will be returned. 



# The flow   
The program is mostly composed of three main processes that happens in a sequence for each input received, the order is essential, considering that the necessary information for the next action will be gathered during the preceding process.  

## lexer;  
The lexer receives the input string from the readline function, this line will contain the user input. This input, then, will be segmented into a linked list containing its parts, treated internally as tokens.

Tokens are classified based on the internal CFG of the SEAshell.  

## parser;  
The parser will receive the token list from the lexer, then, this list will be interpreted by the automaton, validating a correct input, and, also, creating the list of commands, to be executed.
The process will open all file descriptors necessary for pipes or file manipulation that will be used during the process of execution.  

## exec;  
The exec will receive the command table from the parser, then, this table will be executed one by one, using the pre-stabilished file descritors for input and output.  

# Parser functionality;  

The parser will utilize of a pushdown automaton with a finite set of states initialized to parse the desired language to create a command table based on the tokens provided by the lexer.  

If, at any point during parsing of the tokens the automaton find a non-action, or a FALSE_INDEX, the parser will return NULL.  

