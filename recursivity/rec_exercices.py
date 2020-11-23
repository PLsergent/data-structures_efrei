def multiply(a: int = 2, b: int = 2) -> int:
    if b == 0: return 0
    return a + multiply(a, b-1)


def enum(n: int = 0, range: int = 30):
    if n != range:
        n += 1
        print(n, end=" ")
        enum(n, range)
    else:
        print()

def hanoi(n , source, destination, auxiliary):
    if n == 1: 
        print("Move disk 1 from source", source, "to destination", destination)
        return

    hanoi(n-1, source, auxiliary, destination) 
    print("Move disk", n, "from source", source, "to destination", destination)
    hanoi(n-1, auxiliary, destination, source)


"""
expr : term | term + term
term : factor | factor * factor
factor : a | ( expr )
"""

def expr(string):
    if not term(string):
        return 0
    
    c = list(string)[0]

    if c != '+':
        return 1
    return term("".join(list(string)[1:]))

def term(string):
    if not factor(string):
        return 0
    
    c = list(string)[0]

    if c != '*':
        return 1
    return factor("".join(list(string)[1:]))

def factor(string):
    if string == "": return 0

    c = list(string)[0]

    string = "".join(list(string)[1:])

    if c == 'a' or c == '(':
        if c == 'a': return 1

        if expr(string) and list(string)[0] == ')':
            return 1
        else:
            return 0
    return 0


if __name__ == "__main__":
    print("Multiply :", multiply())
    print("Enum :", end=" ")
    enum()
    print("Hanoi: ")
    hanoi(3, 'A', 'C', 'B')
    
    string = "a+a"
    if (expr(string) and string != ""):
        print(f"expr {string} is valid")
    else:
        print(f"expr {string} is not valid")
