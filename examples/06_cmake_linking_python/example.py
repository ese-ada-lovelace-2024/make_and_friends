def do_sum(*args):
    return sum(args)

def do_product(*args):
    return reduce(lambda x, y: x * y, args)

def do_min(*args):
    return min(args)

def do_max(*args):
    return max(args)