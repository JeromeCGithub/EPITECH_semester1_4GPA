#!/usr/bin/env python3

import sys

def help(binname):
    with open("help.txt", "r") as f:
        helpfile = f.read().split("%s")
        helpfile = binname.join(helpfile)
        print(helpfile, end='')
        
def readfile(filepath):
    try:
        with open(filepath, "r") as f:
            values = f.read().split("\n")
            if (len(values) < 3):
                exit(84)
            for i in range(len(values)):
                if (not(len(values[i])) and i == len(values) - 1):
                    values.pop(-1)
                    return (values);
                values[i] = values[i].split(";")
                if (len(values[i]) != 2):
                    exit(84)
                for j in range(len(values[i])):
                    try:
                        values[i][j] = float(values[i][j])
                    except:
                        exit(84)
                if (values[i][0] < 0 or values[i][1] > 14 or values[i][1] < 0):
                    exit(84)
            return (values)
    except:
        exit(84)

def rate_of_change(p1, p2):
    return ((p2[1] - p1[1]) / (p2[0] - p1[0]))

def derivative_estimation(p1, p2, p3):
    a = p2[0] - p1[0]
    b = p3[0] - p2[0]
    x = rate_of_change(p1, p2)
    y = rate_of_change(p2, p3)
    return (b * x + a * y) / (a + b)

def derivative(values, is_equivalence_point):
    record = 0
    index = 0
    new_values = []
    for i in range(1, len(values) - 1):
        values[i].append(derivative_estimation(values[i - 1], values[i], values[i + 1]))
        temp = []
        temp.append(values[i][0])
        temp.append(values[i][2])
        new_values.append(temp)
        if (record < values[i][2]):
            record = values[i][2]
            index = i
        print (values[i][0], "ml", "->", f'{values[i][2]:.2f}')
    if (is_equivalence_point):
        print ("\nEquivalence point at", f'{values[index][0]:.1f}', "ml")
    return (new_values, values[index][0])

def estimation(value1, value2):
    values = []
    nb_iter = (value2[0] - value1[0]) * 10
    diff = (value2[1] - value1[1]) / nb_iter
    i = value1[0]
    index = 0
    values.append(value1) 
    while (index < nb_iter - 1):
        i += 0.1
        index += 1
        values.append([i, values[index - 1][1] + diff])
    return (values)

def second_eq_point(values):
    for j in range(len(values)):
        print (f'{values[j][0]:.1f}', "ml", "->", f'{values[j][1]:.2f}')
        if (j > 0 and values[j][1] < 0 and values[j - 1][1] >= 0):
            equivalence_point = values[j][0]
    print ("\nEquivalence point at", f'{equivalence_point:.1f}', "ml")

def titration(filepath):
    index = 0
    i = 0
    new_values = []
    temp = []
    values = readfile(filepath)
    print("Derivative:")
    values, index = derivative(values, True)
    print ("\nSecond derivative:")
    values, nb = derivative(values, False)
    print ("\nSecond derivative estimated:")
    if (not(len(values))):
        return;
    while (values[i][0] < index):
        i += 1
        if (i >= len(values) - 1):
            return
    temp = estimation(values[i - 1], values[i])
    for j in temp:
        new_values.append(j)
    temp = estimation(values[i], values[i + 1])
    for j in temp:
        new_values.append(j)
    new_values.append([values[i + 1][0], values[i + 1][1]])
    second_eq_point(new_values)

def main(av):
    if (len(av) != 2):
        exit(84)
    if (av[1] == "-h"):
        help(av[0])
        exit(0)
    titration(av[1])

if __name__ == "__main__":
    main(sys.argv)
