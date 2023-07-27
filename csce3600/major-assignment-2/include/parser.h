// Group 10: Dhruv Chanana, Alicia Lin, Kelly Zhou, Mark White
// CSCE 3600.002, Spring 2023
// Major Assignment 2

#pragma once

#include <stdbool.h>

// Types of AST node
typedef enum { Command, Semicolon, Pipeline, RedirRight, RedirLeft } ExprType;

// AST node structure, or expression
struct Expr {
  ExprType type;
  bool alias;
  struct Expr *left;
  struct Expr *right;

  char *args;
};

// Execute function
void execute(struct Expr *expression);

// Build abstract syntax tree (AST)
struct Expr **buildTree(char *line);
