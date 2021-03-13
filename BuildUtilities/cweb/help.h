const_string CTANGLEHELP[] = {
    "Usage: ctangle [OPTIONS] WEBFILE[.w] [{CHANGEFILE[.ch]|-} [OUTFILE[.c]]]",
    "  Tangle WEBFILE with CHANGEFILE into a C/C++ program.",
    "  Default CHANGEFILE is /dev/null;",
    "  C output goes to the basename of WEBFILE extended with `.c'",
    "  unless otherwise specified by OUTFILE; in this case, '-' specifies",
    "  a null CHANGEFILE.",
    "",
    "-b          suppress banner line on terminal",
    "-h          suppress success message on completion",
    "-p          suppress progress report messages",
    "+s          print usage statistics",
    "--help      display this help and exit",
    "--version   output version information and exit",
    NULL
};
