#include "TreeGram.hh"
#include "TreeGramArpaReader.hh"

int
main(int argc, char *argv[])
{
  TreeGram g;

  // Read the model
  if (argc > 1) {
    TreeGramArpaReader r;
    r.read(stdin, &g);
  }
  else {
    g.read(stdin);
  }

  // Print the model
  if (argc > 2) {
    TreeGram::Iterator i(&g);
    while (i.next()) {
      fprintf(stderr, "( ");
      for (int o = 1; o <= i.order(); o++)
	fprintf(stderr, "%d ", i.node(o).word);
      fprintf(stderr, ") %g %g\n", i.node().log_prob, i.node().back_off);
    }
  }

  g.write(stdout, false);
}
