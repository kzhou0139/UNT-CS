// Group 10: Dhruv Chanana, Alicia Lin, Kelly Zhou, Mark White
// CSCE 3600.002, Spring 2023
// Major Assignment 2

#pragma once

#include "parser.h"
#include "shell.h"

// AST node executors
void executeCommand(struct Expr *expression);
void executePipeline(struct Expr *expression);
void executeSemicolon(struct Expr *expression);
void executeRedirLeft(struct Expr *expression);
void executeRedirRight(struct Expr *expression);
