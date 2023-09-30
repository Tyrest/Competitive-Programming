
word = input()


def isnumber(word):
    
     
    if word == "zero":
        return True
    elif word == "one":
        return True
    elif word ==  "two":
        return True
    elif word ==  "three":
        return True
    elif word ==  "four":
        return True
    elif word ==  "five":
        return True
    elif word == "six":
        return True
    elif word ==  "seven":
        return True
    elif word == "eight":
        return True
    elif word ==  "nine":
        return True
    else:
        return False

columns = len(word) + 1
rows = int(columns / 3) + 2



results = []
uniqueness = [1]

for i in range(rows):
    results.append([])
    uniqueness.append(1)
    for j in range(columns):
        if (i == 0):
            results[i].append(j)
        else:
            if (j == 0):
                results[i].append(0)
            else:
                subword = word[:j]
                threeword = subword[-3:]
                fourword = subword[-4:]
                fiveword = subword [-5:]
                if (isnumber(threeword)):
                    if (j - 3 >= 0):
                        previous_best = results[i-1][j-3]
                        if (previous_best < results[i][j-1]):
                            results[i].append( previous_best + 1)
                        elif (previous_best == results[i][j-1]):
                            results[i].append( previous_best + 1)
                            uniqueness[i] += 1
                        else:
                            results[i].append (results[i][j-1] + 1)
                elif (isnumber(fourword)):
                    if (j - 4 >= 0):
                        previous_best = results[i-1][j-4]
                        if (previous_best < results[i][j-1]):
                            results[i].append( previous_best + 1)
                        elif (previous_best == results[i][j-1]):
                            results[i].append( previous_best + 1)
                            uniqueness[i] += 1
                        else:
                            results[i].append (results[i][j-1] + 1)
                elif(isnumber(fiveword)):
                    if (j - 5 >= 0):
                        previous_best = results[i-1][j-5]
                        if (previous_best < results[i][j-1]):
                            results[i].append( previous_best + 1)
                        elif (previous_best == results[i][j-1]):
                            results[i].append( previous_best + 1)
                            uniqueness[i] += 1
                        else:
                            results[i].append (results[i][j-1] + 1)
                else:
                    results[i].append(results[i][j-1] + 1)
    #print(results[i])

print(results[i][j])
print(uniqueness[i])
    



