
from contextlib import contextmanager


@contextmanager
def custom():
    print('entering')
    try:
        yield 'Resource'
    finally:
        print('exiting')
    
with custom() as res:
    print(f'using {res}')
    raise ValueError('an error oc')