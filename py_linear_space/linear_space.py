from functools import total_ordering


# this special function will help me not to do lots of similar functions
@total_ordering
class lin_space:
    # contains linear shell of given vectors
    def __init__(self, *args, n=3):
        # we include in our shell only vectors with len==n
        if len(args) == 1 and len(args[0]) != 0 and hasattr(args[0][0], '__getitem__'):
            # it was made for giving matrix as an argument
            args = args[0]
        self.vec = [args[i] for i in range(len(args)) if len(args[i]) == n]
        # think a bit and you'll understand that this the most elegant solution for matrix and some vectors
        self.n = n

    def __lshift__(self, other):
        # this is combination of 2 linear shell
        self.vec += other.vec
        return self

    def __rshift__(self, other):
        # this function returns vectors from self without vectors from other
        for v in other.vec:
            try:
                self.vec.remove(v)
            except ValueError:
                pass
        return self

    def __getitem__(self, item):
        return self.vec[item]

    def _staff_gauss(self):
        from copy import deepcopy
        # copy of matrix, but quiet unusual -- matrix[i][j] means cell on i-th column and j-th string
        matrix = deepcopy(self.vec)
        step_cells = list()  # it will be a list with coordinates of cells, that have 'step'
        col_num = 0
        str_num = 0
        while str_num in range(self.n):
            # at first we should stop if the columns ran out
            if col_num == len(matrix):
                break
            # str_num is a number of a string
            # now we are finding first non-zero element in matrix[col_num]
            try:
                non_zero = matrix[col_num][str_num:].index(
                    list(filter(lambda x: x != 0, matrix[col_num][str_num:]))[0]) + str_num
            except IndexError:
                # we go here if all numbers in matrix[col_num] are 0
                col_num += 1
                continue
            for c_n in range(col_num, len(matrix)):
                # here we change the order of strings so, that our string will have non-zero item in our column
                matrix[c_n][non_zero], matrix[c_n][str_num] = matrix[c_n][str_num], matrix[c_n][non_zero]
            # and only now we do arithmetic operations
            for s_n in range(str_num + 1, self.n):
                coefficient = matrix[col_num][s_n] / matrix[col_num][str_num]
                for c_n in range(col_num, len(matrix)):
                    matrix[c_n][s_n] -= coefficient * matrix[c_n][str_num]
            # the step is finished, so let's go to another column
            step_cells.append((col_num, str_num))
            # we know, that added cell is nonzero
            str_num += 1
            col_num += 1

        # so, that was straight part of gauss - let's go back
        for st_cell in step_cells:
            val = matrix[st_cell[0]][st_cell[1]]
            for col_num in range(st_cell[0], len(matrix)):
                # let's make 1 on step cells
                matrix[col_num][st_cell[1]] /= val
                for str_num in range(0, st_cell[1]):
                    matrix[col_num][str_num] -= matrix[st_cell[0]][str_num] * matrix[col_num][st_cell[1]]
        return [lin_space(matrix, n=self.n), step_cells]

    def gauss(self):
        return self._staff_gauss()[0]

    def step_cells(self):
        return self._staff_gauss()[1]

    def basis(self):
        step_cells = self.step_cells()
        return list(self.vec[step_cell[0]] for step_cell in step_cells)

    def dim(self):
        return len(self.basis())

    def __ge__(self, other):
        from copy import deepcopy
        copy_self = deepcopy(self)
        return (copy_self << other).basis() == self.basis()

    def __eq__(self, other):
        return self >= other and self.dim() == other.dim()

    def __str__(self):
        # for good looking matrix we find max length of each column in functional style of programming
        # and we do it for any type of elements in self.vec[i][j]
        col_len = list(max(list(len(str(self[col_num][str_num])) for str_num in range(self.n))) for col_num in
                       range(len(self.vec)))
        ret = ''
        for str_num in range(self.n):
            ret += '['
            for col_num in range(len(self.vec)):
                ret += str(self[col_num][str_num]) + ' ' * (col_len[col_num] - len(str(self[col_num][str_num]))) + ','
            if len(self.vec) != 0:
                ret = ret[:-1]
            ret += ']\n'
        # we should return ret without '\n' in the end
        return ret[:-1]
