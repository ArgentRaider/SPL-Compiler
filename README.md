# SPL Compiler

A project for the course 'Compilers'.

### Project Progress
- [x] Lexical Analysis (using flex)
- [x] Parsing (using Bison) (All test cases except 'array.spl' passed.)
- [ ] AST
- [ ] Semantic Analysis
- [ ] IR Generator (plan to use LLVM API)
- [ ] Backend (plan to use LLVM)

### Target Features
- [x] Error locating in lexical analysis
- [ ] Error locating in parsing
- [ ] Store location information in AST nodes for error locating in semantic analysis

### Troubles
1. The token 'READ' appears in the syntax part but not in the lexical part. It will generate a seperate token 'T_READ' from 'T_SYS_PROC' now.
2. I personally divided 'simple_type_decl' into 2 parts: 'simple_type_decl' & 'array_type_range_decl'.
3. In one test case there is a line writes 'array[1..5,2..3,0..2]' which is not actually a legal declaration according to the parsing rules.
4. Now the 'string' with length 1 will always be considered as a 'char' first, which means we need to be able to transform a 'char' into 'string' implicitly.
5. ...

### More
Who knows? Maybe I should review 'Sherlock' sometime to help me decuct what's left to do.