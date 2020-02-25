#include "X.h"
#include "libft.h"
#include "mlx.h"
#include <string.h>
#include <stdio.h>

int key_event(int key, void *param)
{
    (void)param;
    ft_putnbr_fd(key, 1);
    ft_putchar_fd('\n', 1);
    return(0);
}

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    // int     i;
    // char    *buff;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 900, 900, "test window");

    mlx_hook(win_ptr, KeyPress, KeyPressMask, &key_event, NULL);
    mlx_loop(mlx_ptr);
    return(0);
}
