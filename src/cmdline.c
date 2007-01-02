/*
  File autogenerated by gengetopt version 2.19rc
  generated with the following command:
  ../src/gengetopt --input=cmdline.ggo --no-handle-version --no-handle-help --no-handle-error --string-parser

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "This program generates a C function that uses getopt_long function\nto parse the command line options, validate them and fill a struct.";

const char *gengetopt_args_info_usage = "Usage: gengetopt [OPTIONS]...";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                    Print help and exit",
  "  -V, --version                 Print version and exit",
  "\nMain options:",
  "",
  "  -i, --input=filename          input file (default std input)",
  "  -f, --func-name=name          name of generated function  \n                                  (default=`cmdline_parser')",
  "  -a, --arg-struct-name=name    name of generated args info struct  \n                                  (default=`gengetopt_args_info')",
  "  -F, --file-name=name          name of generated file  (default=`cmdline')",
  "      --output-dir=path         output directory",
  "  -c, --c-extension=ext         extension of c file  (default=`c')",
  "  -H, --header-extension=ext    extension of header file  (default=`h')",
  "  -l, --long-help               long usage line in help",
  "  -u, --unamed-opts[=STRING]    accept options without names (e.g., file names) \n                                   (default=`FILES')",
  "\nThe parser generated is thought to be used to parse the command line arguments. \nHowever, you can also generate parsers for configuration files, or strings that \ncontain the arguments to parse, by using the following two options.\n",
  "  -C, --conf-parser             generate a config file parser",
  "  -S, --string-parser           generate a string parser (the string contains \n                                  the command line)",
  "\nAdditional options:",
  "",
  "  -G, --include-getopt          adds the code for getopt_long in the generated \n                                  C file",
  "  -n, --no-handle-help          do not handle --help|-h automatically",
  "  -N, --no-handle-version       do not handle --version|-V automatically",
  "  -e, --no-handle-error         do not exit on errors",
  "      --show-required[=STRING]  in the output of help will specify which \n                                  options are mandatory, by using the optional \n                                  passed string  (default=`(mandatory)')",
  "  -g, --gen-version             put gengetopt version in the generated file  \n                                  (default=on)",
  "      --set-package=STRING      set the package name (override package defined \n                                  in the .ggo file)",
  "      --set-version=STRING      set the version number (override version \n                                  defined in the .ggo file)",
  "      --show-help               show the output of --help instead of generating \n                                  code",
  "      --show-full-help          show the output of --help (including hidden \n                                  options) instead of generating code",
  "      --show-version            show the output of --version instead of \n                                  generating code",
  "\nPlease refer to the manual for further explanations.",
    0
};

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error);

struct line_list
{
  char * string_arg;
  struct line_list * next;
};

static struct line_list *cmd_line_list = 0;
static struct line_list *cmd_line_list_tmp = 0;

static void
free_cmd_list(void)
{
  /* free the list of a previous call */
  if (cmd_line_list)
    {
      while (cmd_line_list) {
        cmd_line_list_tmp = cmd_line_list;
        cmd_line_list = cmd_line_list->next;
        free (cmd_line_list_tmp->string_arg);
        free (cmd_line_list_tmp);
      }
    }
}


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->input_given = 0 ;
  args_info->func_name_given = 0 ;
  args_info->arg_struct_name_given = 0 ;
  args_info->file_name_given = 0 ;
  args_info->output_dir_given = 0 ;
  args_info->c_extension_given = 0 ;
  args_info->header_extension_given = 0 ;
  args_info->long_help_given = 0 ;
  args_info->unamed_opts_given = 0 ;
  args_info->conf_parser_given = 0 ;
  args_info->string_parser_given = 0 ;
  args_info->include_getopt_given = 0 ;
  args_info->no_handle_help_given = 0 ;
  args_info->no_handle_version_given = 0 ;
  args_info->no_handle_error_given = 0 ;
  args_info->show_required_given = 0 ;
  args_info->gen_version_given = 0 ;
  args_info->set_package_given = 0 ;
  args_info->set_version_given = 0 ;
  args_info->show_help_given = 0 ;
  args_info->show_full_help_given = 0 ;
  args_info->show_version_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  args_info->input_arg = NULL;
  args_info->input_orig = NULL;
  args_info->func_name_arg = gengetopt_strdup ("cmdline_parser");
  args_info->func_name_orig = NULL;
  args_info->arg_struct_name_arg = gengetopt_strdup ("gengetopt_args_info");
  args_info->arg_struct_name_orig = NULL;
  args_info->file_name_arg = gengetopt_strdup ("cmdline");
  args_info->file_name_orig = NULL;
  args_info->output_dir_arg = NULL;
  args_info->output_dir_orig = NULL;
  args_info->c_extension_arg = gengetopt_strdup ("c");
  args_info->c_extension_orig = NULL;
  args_info->header_extension_arg = gengetopt_strdup ("h");
  args_info->header_extension_orig = NULL;
  args_info->unamed_opts_arg = gengetopt_strdup ("FILES");
  args_info->unamed_opts_orig = NULL;
  args_info->show_required_arg = gengetopt_strdup ("(mandatory)");
  args_info->show_required_orig = NULL;
  args_info->gen_version_flag = 1;
  args_info->set_package_arg = NULL;
  args_info->set_package_orig = NULL;
  args_info->set_version_arg = NULL;
  args_info->set_version_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{
  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->input_help = gengetopt_args_info_help[3] ;
  args_info->func_name_help = gengetopt_args_info_help[4] ;
  args_info->arg_struct_name_help = gengetopt_args_info_help[5] ;
  args_info->file_name_help = gengetopt_args_info_help[6] ;
  args_info->output_dir_help = gengetopt_args_info_help[7] ;
  args_info->c_extension_help = gengetopt_args_info_help[8] ;
  args_info->header_extension_help = gengetopt_args_info_help[9] ;
  args_info->long_help_help = gengetopt_args_info_help[10] ;
  args_info->unamed_opts_help = gengetopt_args_info_help[11] ;
  args_info->conf_parser_help = gengetopt_args_info_help[12] ;
  args_info->string_parser_help = gengetopt_args_info_help[13] ;
  args_info->include_getopt_help = gengetopt_args_info_help[15] ;
  args_info->no_handle_help_help = gengetopt_args_info_help[16] ;
  args_info->no_handle_version_help = gengetopt_args_info_help[17] ;
  args_info->no_handle_error_help = gengetopt_args_info_help[18] ;
  args_info->show_required_help = gengetopt_args_info_help[19] ;
  args_info->gen_version_help = gengetopt_args_info_help[20] ;
  args_info->set_package_help = gengetopt_args_info_help[21] ;
  args_info->set_version_help = gengetopt_args_info_help[22] ;
  args_info->show_help_help = gengetopt_args_info_help[23] ;
  args_info->show_full_help_help = gengetopt_args_info_help[24] ;
  args_info->show_version_help = gengetopt_args_info_help[25] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", CMDLINE_PARSER_PACKAGE, CMDLINE_PARSER_VERSION);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  printf("\n%s\n\n", gengetopt_args_info_usage);
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  
  if (args_info->input_arg)
    {
      free (args_info->input_arg); /* free previous argument */
      args_info->input_arg = 0;
    }
  if (args_info->input_orig)
    {
      free (args_info->input_orig); /* free previous argument */
      args_info->input_orig = 0;
    }
  if (args_info->func_name_arg)
    {
      free (args_info->func_name_arg); /* free previous argument */
      args_info->func_name_arg = 0;
    }
  if (args_info->func_name_orig)
    {
      free (args_info->func_name_orig); /* free previous argument */
      args_info->func_name_orig = 0;
    }
  if (args_info->arg_struct_name_arg)
    {
      free (args_info->arg_struct_name_arg); /* free previous argument */
      args_info->arg_struct_name_arg = 0;
    }
  if (args_info->arg_struct_name_orig)
    {
      free (args_info->arg_struct_name_orig); /* free previous argument */
      args_info->arg_struct_name_orig = 0;
    }
  if (args_info->file_name_arg)
    {
      free (args_info->file_name_arg); /* free previous argument */
      args_info->file_name_arg = 0;
    }
  if (args_info->file_name_orig)
    {
      free (args_info->file_name_orig); /* free previous argument */
      args_info->file_name_orig = 0;
    }
  if (args_info->output_dir_arg)
    {
      free (args_info->output_dir_arg); /* free previous argument */
      args_info->output_dir_arg = 0;
    }
  if (args_info->output_dir_orig)
    {
      free (args_info->output_dir_orig); /* free previous argument */
      args_info->output_dir_orig = 0;
    }
  if (args_info->c_extension_arg)
    {
      free (args_info->c_extension_arg); /* free previous argument */
      args_info->c_extension_arg = 0;
    }
  if (args_info->c_extension_orig)
    {
      free (args_info->c_extension_orig); /* free previous argument */
      args_info->c_extension_orig = 0;
    }
  if (args_info->header_extension_arg)
    {
      free (args_info->header_extension_arg); /* free previous argument */
      args_info->header_extension_arg = 0;
    }
  if (args_info->header_extension_orig)
    {
      free (args_info->header_extension_orig); /* free previous argument */
      args_info->header_extension_orig = 0;
    }
  if (args_info->unamed_opts_arg)
    {
      free (args_info->unamed_opts_arg); /* free previous argument */
      args_info->unamed_opts_arg = 0;
    }
  if (args_info->unamed_opts_orig)
    {
      free (args_info->unamed_opts_orig); /* free previous argument */
      args_info->unamed_opts_orig = 0;
    }
  if (args_info->show_required_arg)
    {
      free (args_info->show_required_arg); /* free previous argument */
      args_info->show_required_arg = 0;
    }
  if (args_info->show_required_orig)
    {
      free (args_info->show_required_orig); /* free previous argument */
      args_info->show_required_orig = 0;
    }
  if (args_info->set_package_arg)
    {
      free (args_info->set_package_arg); /* free previous argument */
      args_info->set_package_arg = 0;
    }
  if (args_info->set_package_orig)
    {
      free (args_info->set_package_orig); /* free previous argument */
      args_info->set_package_orig = 0;
    }
  if (args_info->set_version_arg)
    {
      free (args_info->set_version_arg); /* free previous argument */
      args_info->set_version_arg = 0;
    }
  if (args_info->set_version_orig)
    {
      free (args_info->set_version_orig); /* free previous argument */
      args_info->set_version_orig = 0;
    }
  
  clear_given (args_info);
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  if (args_info->help_given) {
    fprintf(outfile, "%s\n", "help");
  }
  if (args_info->version_given) {
    fprintf(outfile, "%s\n", "version");
  }
  if (args_info->input_given) {
    if (args_info->input_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "input", args_info->input_orig);
    } else {
      fprintf(outfile, "%s\n", "input");
    }
  }
  if (args_info->func_name_given) {
    if (args_info->func_name_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "func-name", args_info->func_name_orig);
    } else {
      fprintf(outfile, "%s\n", "func-name");
    }
  }
  if (args_info->arg_struct_name_given) {
    if (args_info->arg_struct_name_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "arg-struct-name", args_info->arg_struct_name_orig);
    } else {
      fprintf(outfile, "%s\n", "arg-struct-name");
    }
  }
  if (args_info->file_name_given) {
    if (args_info->file_name_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "file-name", args_info->file_name_orig);
    } else {
      fprintf(outfile, "%s\n", "file-name");
    }
  }
  if (args_info->output_dir_given) {
    if (args_info->output_dir_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "output-dir", args_info->output_dir_orig);
    } else {
      fprintf(outfile, "%s\n", "output-dir");
    }
  }
  if (args_info->c_extension_given) {
    if (args_info->c_extension_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "c-extension", args_info->c_extension_orig);
    } else {
      fprintf(outfile, "%s\n", "c-extension");
    }
  }
  if (args_info->header_extension_given) {
    if (args_info->header_extension_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "header-extension", args_info->header_extension_orig);
    } else {
      fprintf(outfile, "%s\n", "header-extension");
    }
  }
  if (args_info->long_help_given) {
    fprintf(outfile, "%s\n", "long-help");
  }
  if (args_info->unamed_opts_given) {
    if (args_info->unamed_opts_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "unamed-opts", args_info->unamed_opts_orig);
    } else {
      fprintf(outfile, "%s\n", "unamed-opts");
    }
  }
  if (args_info->conf_parser_given) {
    fprintf(outfile, "%s\n", "conf-parser");
  }
  if (args_info->string_parser_given) {
    fprintf(outfile, "%s\n", "string-parser");
  }
  if (args_info->include_getopt_given) {
    fprintf(outfile, "%s\n", "include-getopt");
  }
  if (args_info->no_handle_help_given) {
    fprintf(outfile, "%s\n", "no-handle-help");
  }
  if (args_info->no_handle_version_given) {
    fprintf(outfile, "%s\n", "no-handle-version");
  }
  if (args_info->no_handle_error_given) {
    fprintf(outfile, "%s\n", "no-handle-error");
  }
  if (args_info->show_required_given) {
    if (args_info->show_required_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "show-required", args_info->show_required_orig);
    } else {
      fprintf(outfile, "%s\n", "show-required");
    }
  }
  if (args_info->gen_version_given) {
    fprintf(outfile, "%s\n", "gen-version");
  }
  if (args_info->set_package_given) {
    if (args_info->set_package_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "set-package", args_info->set_package_orig);
    } else {
      fprintf(outfile, "%s\n", "set-package");
    }
  }
  if (args_info->set_version_given) {
    if (args_info->set_version_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "set-version", args_info->set_version_orig);
    } else {
      fprintf(outfile, "%s\n", "set-version");
    }
  }
  if (args_info->show_help_given) {
    fprintf(outfile, "%s\n", "show-help");
  }
  if (args_info->show_full_help_given) {
    fprintf(outfile, "%s\n", "show-full-help");
  }
  if (args_info->show_version_given) {
    fprintf(outfile, "%s\n", "show-version");
  }
  
  fclose (outfile);

  i = EXIT_SUCCESS;
  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}


/* gengetopt_strdup() */
/* strdup.c replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = NULL;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser2 (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;

  result = cmdline_parser_internal (argc, argv, args_info, override, initialize, check_required, NULL);

  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  return EXIT_SUCCESS;
}

int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error = 0;
  struct gengetopt_args_info local_args_info;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = 1;
  optopt = '?';

  while (1)
    {
      int option_index = 0;
      char *stop_char;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "input",	1, NULL, 'i' },
        { "func-name",	1, NULL, 'f' },
        { "arg-struct-name",	1, NULL, 'a' },
        { "file-name",	1, NULL, 'F' },
        { "output-dir",	1, NULL, 0 },
        { "c-extension",	1, NULL, 'c' },
        { "header-extension",	1, NULL, 'H' },
        { "long-help",	0, NULL, 'l' },
        { "unamed-opts",	2, NULL, 'u' },
        { "conf-parser",	0, NULL, 'C' },
        { "string-parser",	0, NULL, 'S' },
        { "include-getopt",	0, NULL, 'G' },
        { "no-handle-help",	0, NULL, 'n' },
        { "no-handle-version",	0, NULL, 'N' },
        { "no-handle-error",	0, NULL, 'e' },
        { "show-required",	2, NULL, 0 },
        { "gen-version",	0, NULL, 'g' },
        { "set-package",	1, NULL, 0 },
        { "set-version",	1, NULL, 0 },
        { "show-help",	0, NULL, 0 },
        { "show-full-help",	0, NULL, 0 },
        { "show-version",	0, NULL, 0 },
        { NULL,	0, NULL, 0 }
      };

      stop_char = 0;
      c = getopt_long (argc, argv, "hVi:f:a:F:c:H:lu::CSGnNeg", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          if (local_args_info.help_given)
            {
              fprintf (stderr, "%s: `--help' (`-h') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->help_given && ! override)
            continue;
          local_args_info.help_given = 1;
          args_info->help_given = 1;
          cmdline_parser_free (&local_args_info);
          return 0;

        case 'V':	/* Print version and exit.  */
          if (local_args_info.version_given)
            {
              fprintf (stderr, "%s: `--version' (`-V') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->version_given && ! override)
            continue;
          local_args_info.version_given = 1;
          args_info->version_given = 1;
          cmdline_parser_free (&local_args_info);
          return 0;

        case 'i':	/* input file (default std input).  */
          if (local_args_info.input_given)
            {
              fprintf (stderr, "%s: `--input' (`-i') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->input_given && ! override)
            continue;
          local_args_info.input_given = 1;
          args_info->input_given = 1;
          if (args_info->input_arg)
            free (args_info->input_arg); /* free previous string */
          args_info->input_arg = gengetopt_strdup (optarg);
          if (args_info->input_orig)
            free (args_info->input_orig); /* free previous string */
          args_info->input_orig = gengetopt_strdup (optarg);
          break;

        case 'f':	/* name of generated function.  */
          if (local_args_info.func_name_given)
            {
              fprintf (stderr, "%s: `--func-name' (`-f') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->func_name_given && ! override)
            continue;
          local_args_info.func_name_given = 1;
          args_info->func_name_given = 1;
          if (args_info->func_name_arg)
            free (args_info->func_name_arg); /* free previous string */
          args_info->func_name_arg = gengetopt_strdup (optarg);
          if (args_info->func_name_orig)
            free (args_info->func_name_orig); /* free previous string */
          args_info->func_name_orig = gengetopt_strdup (optarg);
          break;

        case 'a':	/* name of generated args info struct.  */
          if (local_args_info.arg_struct_name_given)
            {
              fprintf (stderr, "%s: `--arg-struct-name' (`-a') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->arg_struct_name_given && ! override)
            continue;
          local_args_info.arg_struct_name_given = 1;
          args_info->arg_struct_name_given = 1;
          if (args_info->arg_struct_name_arg)
            free (args_info->arg_struct_name_arg); /* free previous string */
          args_info->arg_struct_name_arg = gengetopt_strdup (optarg);
          if (args_info->arg_struct_name_orig)
            free (args_info->arg_struct_name_orig); /* free previous string */
          args_info->arg_struct_name_orig = gengetopt_strdup (optarg);
          break;

        case 'F':	/* name of generated file.  */
          if (local_args_info.file_name_given)
            {
              fprintf (stderr, "%s: `--file-name' (`-F') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->file_name_given && ! override)
            continue;
          local_args_info.file_name_given = 1;
          args_info->file_name_given = 1;
          if (args_info->file_name_arg)
            free (args_info->file_name_arg); /* free previous string */
          args_info->file_name_arg = gengetopt_strdup (optarg);
          if (args_info->file_name_orig)
            free (args_info->file_name_orig); /* free previous string */
          args_info->file_name_orig = gengetopt_strdup (optarg);
          break;

        case 'c':	/* extension of c file.  */
          if (local_args_info.c_extension_given)
            {
              fprintf (stderr, "%s: `--c-extension' (`-c') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->c_extension_given && ! override)
            continue;
          local_args_info.c_extension_given = 1;
          args_info->c_extension_given = 1;
          if (args_info->c_extension_arg)
            free (args_info->c_extension_arg); /* free previous string */
          args_info->c_extension_arg = gengetopt_strdup (optarg);
          if (args_info->c_extension_orig)
            free (args_info->c_extension_orig); /* free previous string */
          args_info->c_extension_orig = gengetopt_strdup (optarg);
          break;

        case 'H':	/* extension of header file.  */
          if (local_args_info.header_extension_given)
            {
              fprintf (stderr, "%s: `--header-extension' (`-H') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->header_extension_given && ! override)
            continue;
          local_args_info.header_extension_given = 1;
          args_info->header_extension_given = 1;
          if (args_info->header_extension_arg)
            free (args_info->header_extension_arg); /* free previous string */
          args_info->header_extension_arg = gengetopt_strdup (optarg);
          if (args_info->header_extension_orig)
            free (args_info->header_extension_orig); /* free previous string */
          args_info->header_extension_orig = gengetopt_strdup (optarg);
          break;

        case 'l':	/* long usage line in help.  */
          if (local_args_info.long_help_given)
            {
              fprintf (stderr, "%s: `--long-help' (`-l') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->long_help_given && ! override)
            continue;
          local_args_info.long_help_given = 1;
          args_info->long_help_given = 1;
          break;

        case 'u':	/* accept options without names (e.g., file names).  */
          if (local_args_info.unamed_opts_given)
            {
              fprintf (stderr, "%s: `--unamed-opts' (`-u') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->unamed_opts_given && ! override)
            continue;
          local_args_info.unamed_opts_given = 1;
          args_info->unamed_opts_given = 1;
          if (optarg)
            {
              if (args_info->unamed_opts_arg)
                free (args_info->unamed_opts_arg); /* free previous string */
              args_info->unamed_opts_arg = gengetopt_strdup (optarg);
              if (args_info->unamed_opts_orig)
                free (args_info->unamed_opts_orig); /* free previous string */
              args_info->unamed_opts_orig = gengetopt_strdup (optarg);
            }
          break;

        case 'C':	/* generate a config file parser.  */
          if (local_args_info.conf_parser_given)
            {
              fprintf (stderr, "%s: `--conf-parser' (`-C') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->conf_parser_given && ! override)
            continue;
          local_args_info.conf_parser_given = 1;
          args_info->conf_parser_given = 1;
          break;

        case 'S':	/* generate a string parser (the string contains the command line).  */
          if (local_args_info.string_parser_given)
            {
              fprintf (stderr, "%s: `--string-parser' (`-S') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->string_parser_given && ! override)
            continue;
          local_args_info.string_parser_given = 1;
          args_info->string_parser_given = 1;
          break;

        case 'G':	/* adds the code for getopt_long in the generated C file.  */
          if (local_args_info.include_getopt_given)
            {
              fprintf (stderr, "%s: `--include-getopt' (`-G') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->include_getopt_given && ! override)
            continue;
          local_args_info.include_getopt_given = 1;
          args_info->include_getopt_given = 1;
          break;

        case 'n':	/* do not handle --help|-h automatically.  */
          if (local_args_info.no_handle_help_given)
            {
              fprintf (stderr, "%s: `--no-handle-help' (`-n') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->no_handle_help_given && ! override)
            continue;
          local_args_info.no_handle_help_given = 1;
          args_info->no_handle_help_given = 1;
          break;

        case 'N':	/* do not handle --version|-V automatically.  */
          if (local_args_info.no_handle_version_given)
            {
              fprintf (stderr, "%s: `--no-handle-version' (`-N') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->no_handle_version_given && ! override)
            continue;
          local_args_info.no_handle_version_given = 1;
          args_info->no_handle_version_given = 1;
          break;

        case 'e':	/* do not exit on errors.  */
          if (local_args_info.no_handle_error_given)
            {
              fprintf (stderr, "%s: `--no-handle-error' (`-e') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->no_handle_error_given && ! override)
            continue;
          local_args_info.no_handle_error_given = 1;
          args_info->no_handle_error_given = 1;
          break;

        case 'g':	/* put gengetopt version in the generated file.  */
          if (local_args_info.gen_version_given)
            {
              fprintf (stderr, "%s: `--gen-version' (`-g') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->gen_version_given && ! override)
            continue;
          local_args_info.gen_version_given = 1;
          args_info->gen_version_given = 1;
          args_info->gen_version_flag = !(args_info->gen_version_flag);
          break;


        case 0:	/* Long option with no short option */
          /* output directory.  */
          if (strcmp (long_options[option_index].name, "output-dir") == 0)
          {
            if (local_args_info.output_dir_given)
              {
                fprintf (stderr, "%s: `--output-dir' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->output_dir_given && ! override)
              continue;
            local_args_info.output_dir_given = 1;
            args_info->output_dir_given = 1;
            if (args_info->output_dir_arg)
              free (args_info->output_dir_arg); /* free previous string */
            args_info->output_dir_arg = gengetopt_strdup (optarg);
            if (args_info->output_dir_orig)
              free (args_info->output_dir_orig); /* free previous string */
            args_info->output_dir_orig = gengetopt_strdup (optarg);
          }
          /* in the output of help will specify which options are mandatory, by using the optional passed string.  */
          else if (strcmp (long_options[option_index].name, "show-required") == 0)
          {
            if (local_args_info.show_required_given)
              {
                fprintf (stderr, "%s: `--show-required' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->show_required_given && ! override)
              continue;
            local_args_info.show_required_given = 1;
            args_info->show_required_given = 1;
            if (optarg)
              {
                if (args_info->show_required_arg)
                  free (args_info->show_required_arg); /* free previous string */
                args_info->show_required_arg = gengetopt_strdup (optarg);
                if (args_info->show_required_orig)
                  free (args_info->show_required_orig); /* free previous string */
                args_info->show_required_orig = gengetopt_strdup (optarg);
              }
          }
          /* set the package name (override package defined in the .ggo file).  */
          else if (strcmp (long_options[option_index].name, "set-package") == 0)
          {
            if (local_args_info.set_package_given)
              {
                fprintf (stderr, "%s: `--set-package' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->set_package_given && ! override)
              continue;
            local_args_info.set_package_given = 1;
            args_info->set_package_given = 1;
            if (args_info->set_package_arg)
              free (args_info->set_package_arg); /* free previous string */
            args_info->set_package_arg = gengetopt_strdup (optarg);
            if (args_info->set_package_orig)
              free (args_info->set_package_orig); /* free previous string */
            args_info->set_package_orig = gengetopt_strdup (optarg);
          }
          /* set the version number (override version defined in the .ggo file).  */
          else if (strcmp (long_options[option_index].name, "set-version") == 0)
          {
            if (local_args_info.set_version_given)
              {
                fprintf (stderr, "%s: `--set-version' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->set_version_given && ! override)
              continue;
            local_args_info.set_version_given = 1;
            args_info->set_version_given = 1;
            if (args_info->set_version_arg)
              free (args_info->set_version_arg); /* free previous string */
            args_info->set_version_arg = gengetopt_strdup (optarg);
            if (args_info->set_version_orig)
              free (args_info->set_version_orig); /* free previous string */
            args_info->set_version_orig = gengetopt_strdup (optarg);
          }
          /* show the output of --help instead of generating code.  */
          else if (strcmp (long_options[option_index].name, "show-help") == 0)
          {
            if (local_args_info.show_help_given)
              {
                fprintf (stderr, "%s: `--show-help' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->show_help_given && ! override)
              continue;
            local_args_info.show_help_given = 1;
            args_info->show_help_given = 1;
            break;
          }
          /* show the output of --help (including hidden options) instead of generating code.  */
          else if (strcmp (long_options[option_index].name, "show-full-help") == 0)
          {
            if (local_args_info.show_full_help_given)
              {
                fprintf (stderr, "%s: `--show-full-help' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->show_full_help_given && ! override)
              continue;
            local_args_info.show_full_help_given = 1;
            args_info->show_full_help_given = 1;
            break;
          }
          /* show the output of --version instead of generating code.  */
          else if (strcmp (long_options[option_index].name, "show-version") == 0)
          {
            if (local_args_info.show_version_given)
              {
                fprintf (stderr, "%s: `--show-version' option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
                goto failure;
              }
            if (args_info->show_version_given && ! override)
              continue;
            local_args_info.show_version_given = 1;
            args_info->show_version_given = 1;
            break;
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */




  cmdline_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}

static unsigned int
cmdline_parser_create_argv(const char *cmdline_, char ***argv_ptr, const char *prog_name)
{
  char *cmdline, *p;
  size_t n = 0, j;
  int i;

  if (prog_name) {
    cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
    cmd_line_list_tmp->next = cmd_line_list;
    cmd_line_list = cmd_line_list_tmp;
    cmd_line_list->string_arg = gengetopt_strdup (prog_name);

    ++n;
  }

  cmdline = gengetopt_strdup(cmdline_);
  p = cmdline;

  while (p && strlen(p))
    {
      j = strcspn(p, " \t");
      ++n;
      if (j && j < strlen(p))
        {
          p[j] = '\0';

          cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
          cmd_line_list_tmp->next = cmd_line_list;
          cmd_line_list = cmd_line_list_tmp;
          cmd_line_list->string_arg = gengetopt_strdup (p);

          p += (j+1);
          p += strspn(p, " \t");
        }
      else
        {
          cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
          cmd_line_list_tmp->next = cmd_line_list;
          cmd_line_list = cmd_line_list_tmp;
          cmd_line_list->string_arg = gengetopt_strdup (p);

          break;
        }
    }

  *argv_ptr = (char **) malloc((n + 1) * sizeof(char *));
  cmd_line_list_tmp = cmd_line_list;
  for (i = (n-1); i >= 0; --i)
    {
      (*argv_ptr)[i] = cmd_line_list_tmp->string_arg;
      cmd_line_list_tmp = cmd_line_list_tmp->next;
    }

  (*argv_ptr)[n] = NULL;

  free(cmdline);
  return n;
}

int
cmdline_parser_string(const char *cmdline, struct gengetopt_args_info *args_info, const char *prog_name)
{
  return cmdline_parser_string2(cmdline, args_info, prog_name, 0, 1, 1);
}

int
cmdline_parser_string2(const char *cmdline, struct gengetopt_args_info *args_info, const char *prog_name,
    int override, int initialize, int check_required)
{
  char **argv_ptr = 0;
  int result;
  unsigned int argc;
  
  argc = cmdline_parser_create_argv(cmdline, &argv_ptr, prog_name);
  
  result =
    cmdline_parser_internal (argc, argv_ptr, args_info, override, initialize, check_required, 0);
  
  if (argv_ptr)
    {
      free (argv_ptr);
    }

  free_cmd_list();
  
  return result;
}

