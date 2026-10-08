/**
 * ============================================================================
 * Course: Compiler Design Laboratory (BCSE306L)
 * Experiment 9: Three Address Code (TAC) & Directed Acyclic Graph (DAG)
 * Author: Shrri Dharshan D R (Reg No: 23BPS1090)
 * Slot: L23+L24
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_tac(void) {
    printf("============================================================\n");
    printf("   THREE ADDRESS CODE (TAC) WITH COMMON SUBEXPRESSION ELIM  \n");
    printf("============================================================\n\n");

    /* Expression 1 */
    printf("Expression 1: x = (a + b) * (c - d) + (e * f) - (a + b)\n");
    printf("------------------------------------------------------------\n");
    printf("  t1 = a + b        // Common Subexpression (Evaluated once)\n");
    printf("  t2 = c - d        // Compute (c - d)\n");
    printf("  t3 = t1 * t2      // Compute (a + b) * (c - d)\n");
    printf("  t4 = e * f        // Compute (e * f)\n");
    printf("  t5 = t3 + t4      // Compute (a + b)*(c - d) + (e * f)\n");
    printf("  x  = t5 - t1      // Subtract reused common subexpression t1\n\n");

    /* Expression 2 */
    printf("Expression 2: y = ((p + q) * r) + ((p + q) * s) + (r * s)\n");
    printf("------------------------------------------------------------\n");
    printf("  t1 = p + q        // Common Subexpression (Evaluated once)\n");
    printf("  t2 = t1 * r       // Compute (p + q) * r\n");
    printf("  t3 = t1 * s       // Compute (p + q) * s (Reuses t1)\n");
    printf("  t4 = r * s        // Compute (r * s)\n");
    printf("  t5 = t2 + t3      // Compute ((p + q)*r) + ((p + q)*s)\n");
    printf("  y  = t5 + t4      // Final result\n\n");

    /* Expression 3 */
    printf("Expression 3: z = (a * b + c * d) * (e + f) + (a * b)\n");
    printf("------------------------------------------------------------\n");
    printf("  t1 = a * b        // Common Subexpression (Evaluated once)\n");
    printf("  t2 = c * d        // Compute (c * d)\n");
    printf("  t3 = t1 + t2      // Compute (a * b + c * d)\n");
    printf("  t4 = e + f        // Compute (e + f)\n");
    printf("  t5 = t3 * t4      // Compute (a*b + c*d) * (e + f)\n");
    printf("  z  = t5 + t1      // Add reused common subexpression t1\n\n");

    /* Expression 4 */
    printf("Expression 4: res = ((a + b) * (c + d)) + ((a + b) * (c + d)) + ((e + f) * (g - h))\n");
    printf("------------------------------------------------------------\n");
    printf("  t1 = a + b        // Subexpression (a + b)\n");
    printf("  t2 = c + d        // Subexpression (c + d)\n");
    printf("  t3 = t1 * t2      // Common Subexpression ((a + b) * (c + d))\n");
    printf("  t4 = t3 + t3      // Reusing t3 instead of recalculating\n");
    printf("  t5 = e + f        // Compute (e + f)\n");
    printf("  t6 = g - h        // Compute (g - h)\n");
    printf("  t7 = t5 * t6      // Compute (e + f) * (g - h)\n");
    printf("  res = t4 + t7     // Final result\n\n");
}

void display_dag_trees(void) {
    printf("============================================================\n");
    printf("       DIRECTED ACYCLIC GRAPH (DAG) HIERARCHICAL TREES      \n");
    printf("============================================================\n\n");

    printf("DAG 1: x = (a + b) * (c - d) + (e * f) - (a + b)\n");
    printf("Shared Subtree: Node (+) [a, b] is shared by root (-) and child (*)\n\n");
    printf("                     (-) [Root: x]\n");
    printf("                    /   \\\n");
    printf("                 (+)     (+) [SHARED SUBTREE: a + b]\n");
    printf("                /   \\     |\n");
    printf("              (*)   (*)   +-- same pointer as left node below\n");
    printf("             /  \\   / \\\n");
    printf("           (+) (-) (e) (f)\n");
    printf("           / \\ / \\\n");
    printf("          a  b c  d\n\n");

    printf("------------------------------------------------------------\n");
    printf("DAG 2: y = ((p + q) * r) + ((p + q) * s) + (r * s)\n");
    printf("Shared Subtree: Node (+) [p, q] is shared across both multiplicands\n\n");
    printf("                     (+) [Root: y]\n");
    printf("                    /   \\\n");
    printf("                 (+)     (*) [r * s]\n");
    printf("                /   \\    / \\\n");
    printf("              (*)   (*) (r) (s)\n");
    printf("             /  \\   / \\\n");
    printf("           (+) (r) (+) (s)\n");
    printf("          [SHARED: p + q]\n");
    printf("           / \\\n");
    printf("          p   q\n\n");

    printf("------------------------------------------------------------\n");
    printf("DAG 4: res = 2 * ((a+b)*(c+d)) + ((e+f)*(g-h))\n");
    printf("Shared Subtree: Node (*) [(a+b), (c+d)] is completely shared!\n\n");
    printf("                     (+) [Root: res]\n");
    printf("                    /   \\\n");
    printf("                 (+)     (*)\n");
    printf("                /   \\    / \\\n");
    printf("              (*)   (*) (e+f) (g-h)\n");
    printf("             [SHARED NODE: (a+b)*(c+d)]\n");
    printf("              /     \\\n");
    printf("            (+)     (+)\n");
    printf("            / \\     / \\\n");
    printf("           a   b   c   d\n\n");
}

int main(void) {
    display_tac();
    display_dag_trees();
    return 0;
}
