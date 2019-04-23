class Stack:
    def __init__(self):
        self.content = list()

    def push(self, x):
        self.content.append(x)
        return self

    def pop(self):
        # try:
        #     return self.content.pop()
        # except Exception:
        #     return None
        if len(self.content) == 0:
            return None
        else:
            return self.content.pop()

    def is_Full(self):
        return False  # ахахахаха

    def is_Empty(self):
        return True if len(self.content) == 0 else False

    def dump(self):
        print(self.content)
        return self


s = Stack().push(5).push(7).push([9, 4, 4]).push(13).dump()
print(s.is_Empty())
for i in range(7):
    print(s.pop())
print(s.is_Empty())
