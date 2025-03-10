a = dict()
a['q0'] = [('b', 'q5'), ('a', 'q5')]
a['q1'] = [('b', 'q5'), ('a', 'q5')]
a['q0'].append(('q5', 'v'))
a.pop('q0')

print(a)