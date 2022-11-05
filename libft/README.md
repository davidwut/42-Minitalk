# Libft

Collection of commonly used functions during the 42cursus.

## Usage

1. Git clone or add as a git submodule

```sh
git clone git@github.com:davidwut/libft.git
rm -rf libft/.git
```

2. Include the header file

```c
#include "libft/include/libft.h"
```

3. Add a rule that targets `libft.a` in your Makefile and builds it

```Makefile
libft/libft.a:
				$(MAKE) -C libft
```

4. For the final executable, when linking is done, add `libft/libft.a` as the last argument.

```Makefile
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $< -o $@ libft/libft.a
```
