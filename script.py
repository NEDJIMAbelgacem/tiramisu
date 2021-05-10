def split_str(s):
    l = [i.strip() for i in s.split(',')]
    return [i[i.index('*')+1:] for i in l if i[-1] == 'i']

s = input()
print( *split_str(s), sep='\n' )