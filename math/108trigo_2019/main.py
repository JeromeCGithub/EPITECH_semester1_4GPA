#!/usr/bin/env python3

import sys
import math

class Matrix(object):
    def __init__(self, size):
        self.tab = [[0 for j in range(size)] for i in range(size)]
        self.size = size
    def params_to_matrix(argv):
        size = 0
        index = 2
        while (size * size != len(argv) - 2):
            if (size * size > len(argv) - 2):
                exit(84)
            size += 1
        matrix = Matrix(size)
        for i in range(size):
            for j in range(size):
                try:
                    matrix.tab[i][j] = int(argv[index])
                except:
                    exit(84)
                if (index < len(argv) - 1):
                    index += 1
                else:
                    return (matrix)

    def copy(self):
        new = Matrix(self.size)
        for i in range(self.size):
            for j in range(self.size):
                new.tab[i][j] = self.tab[i][j]
        return (new)

    def multiply(self, m2):
        result = Matrix(self.size)
        for i in range(self.size):
            for j in range(self.size):
                for k in range(self.size):
                    result.tab[i][j] += self.tab[i][k] * m2.tab[k][j]
        return (result)
    
    def power(self, power):
        temp = self.copy()
        for i in range(1, power):
            self.tab = self.multiply(temp).tab
        if (power != 0):
            return
        for i in range(self.size):
            for j in range(self.size):
                if (i == j):
                    self.tab[i][j] = 1
                else:
                    self.tab[i][j] = 0

    def add(self, m2):
        for i in range(self.size):
            for j in range(self.size):
                self.tab[i][j] += m2.tab[i][j]

    def display(self):
        for i in range(self.size):
            for j in range(self.size):
                print (f'{self.tab[i][j]:.2f}', end='');
                if (j < self.size - 1):
                    print ('\t', end='')
            print ('')

def factorial(nb):
    if (nb <= 0):
        return (1)
    return (nb * factorial(nb - 1))
                
def my_exp(matrix):
    result = Matrix(matrix.size)
    for n in range(50):
        copy = matrix.copy()
        copy.power(n)
        for i in range(copy.size):
            for j in range(copy.size):
                copy.tab[i][j] /= factorial(n)
        result.add(copy)
    return (result)

def my_cos(matrix):
    result = Matrix(matrix.size)
    for n in range(50):
        copy = matrix.copy()
        copy.power(2 * n)
        for i in range(copy.size):
            for j in range(copy.size):
                copy.tab[i][j] *= (((-1)**n) / factorial(2 * n))
        result.add(copy)
    return (result)

def my_sin(matrix):
    result = Matrix(matrix.size)
    for n in range(50):
        copy = matrix.copy()
        copy.power(2 * n + 1)
        for i in range(copy.size):
            for j in range(copy.size):
                copy.tab[i][j] *= (((-1)**n) / factorial(2 * n + 1))
        result.add(copy)
    return (result)

def my_sinh(matrix):
    result = Matrix(matrix.size)
    for n in range(50):
        copy = matrix.copy()
        copy.power(2 * n + 1)
        for i in range(copy.size):
            for j in range(copy.size):
                copy.tab[i][j] *= 1 / factorial(2 * n + 1)
        result.add(copy)
    return (result)

def my_cosh(matrix):
    result = Matrix(matrix.size)
    for n in range(50):
        copy = matrix.copy()
        copy.power(2 * n)
        for i in range(copy.size):
            for j in range(copy.size):
                copy.tab[i][j] /= factorial(2 * n)
        result.add(copy)
    return (result)

def main(argv):
    if (len(argv) < 2):
        exit(84)
    matrix = Matrix.params_to_matrix(argv)
    if (argv[1] == 'EXP'):
        matrix = my_exp(matrix)
    elif (argv[1] == 'COS'):
        matrix = my_cos(matrix)
    elif (argv[1] == 'SIN'):
        matrix = my_sin(matrix)
    elif (argv[1] == 'COSH'):
        matrix = my_cosh(matrix)
    elif (argv[1] == 'SINH'):
        matrix = my_sinh(matrix)
    else:
        exit(84)
    matrix.display()

if __name__ == "__main__":
    main(sys.argv)
