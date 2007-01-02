/*
 * File automatically generated by
 * gengen 1.0 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#include "generic_option_group.h"

void
generic_option_group_gen_class::generate_generic_option_group(ostream &stream, unsigned int indent)
{
  string indent_str (indent, ' ');
  indent = 0;

  stream << "if (args_info->";
  generate_string (group_var_name, stream, indent + indent_str.length ());
  stream << "_group_counter && override)";
  stream << "\n";
  stream << indent_str;
  stream << "  reset_group_";
  generate_string (group_var_name, stream, indent + indent_str.length ());
  stream << " (args_info);";
  stream << "\n";
  stream << indent_str;
  stream << "args_info->";
  generate_string (group_var_name, stream, indent + indent_str.length ());
  stream << "_group_counter += 1;";
}
