/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:23:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/09/02 14:01:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_get_value(unsigned char *encoded, int size)
{
	int		value;
	int		initial_size;

	value = 0;
	initial_size = size;
	while (size)
	{
		value = value << 8;
		value = value | (*encoded & 0xff);
		++encoded;
		size--;
	}
	if (initial_size == 2)
		return ((short)value);
	return (value);
}

t_op	*ft_get_op_data(int op)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (g_op_tab[i].code == op)
			return (&g_op_tab[i]);
		i++;
	}
	return (NULL);
}

void	write_byte(long value, t_vm *vm, long number, t_process *process)
{
	int		byte;
	long	mult;
	int		i;

	i = 0;
	mult = 256L * 256L * 256L;
	if (value < 0)
		value = mult * 256L + value;
	while (i < 4)
	{
		byte = value / mult;
		vm->memory[ft_loop_memory(process->pc + number + i)] = byte;
		value -= byte * mult;
		mult /= 256L;
		i++;
	}
}

long	get_value_depending_on_type(int pos, t_args *args,
									t_process *process, t_vm *vm)
{
	long	value;

	value = 0;
	if (args->types[pos] == T_REG)
		value = process->reg[args->values[pos] - 1];
	else if (args->types[pos] == T_IND)
		value = vm->memory[ft_loop_memory((process->pc +
										(args->values[pos] % IDX_MOD)))];
	else if (args->types[pos] == T_DIR)
		value = args->values[pos];
	process->carry = 1;
	return (value);
}

int		ft_check_reg_exist(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nb_args)
	{
		if (args->types[i] == T_REG)
		{
			if (args->values[i] < 1 || args->values[i] > REG_NUMBER)
				return (0);
		}
		i++;
	}
	return (1);
}

int		handle_coding_byte(int cursor, t_vm *vm, int op)
{
	int		i;
	char	*coding_byte;

	cursor += 1;
	coding_byte = ft_itoa_base(vm->memory[ft_loop_memory(cursor)], "01");
	if (ft_strlen(coding_byte) < 8)
		coding_byte = ft_strjoin("0", coding_byte);
	i = 0;
	while (i < 6)
	{
		if (get_argument_type(coding_byte + i) == T_REG)
			cursor += 1;
		if (get_argument_type(coding_byte + i) == T_IND)
			cursor += 2;
		if (get_argument_type(coding_byte + i) == T_DIR)
			cursor += ft_get_op_data(op)->label_size;
		i = i + 2;
	}
	return (cursor);
}

int		ft_loop_memory(int value)
{
	int		ret;

	ret = value;
	while (ret < 0)
		ret = MEM_SIZE + ret;
	if (ret >= MEM_SIZE)
		ret = value % MEM_SIZE;
	return (ret);
}

int		get_argument_type(char *bin)
{
	if (ft_strncmp(bin, "10", 2) == 0)
		return (T_DIR);
	else if (ft_strncmp(bin, "11", 2) == 0)
		return (T_IND);
	else if (ft_strncmp(bin, "01", 2) == 0)
		return (T_REG);
	return (0);
}

int		get_int_from_bytes(t_vm *vm, t_process *process, int addr)
{
	int		i;
	long	value;
	int		result[4];

	i = 0;
	while (i < 4)
	{
		result[i] = vm->memory[ft_loop_memory(process->pc + addr + i)];
		i++;
	}
	value = (256L * 256L * 256L * result[0]) + (256L * 256L * result[1])
		+ (256L * result[2]) + result[3];
	return ((int)value);
}

int		get_int_from_two_bytes(t_vm *vm, t_process *process, int addr)
{
	int		i;
	long	value;
	int		result[2];

	i = 0;
	while (i < 2)
	{
		result[i] = vm->memory[ft_loop_memory(process->pc + addr + i)];
		i++;
	}
	value = 256L * result[0] + result[1];
	if (value > (256 * 256) / 2)
		value -= 256 * 256;
	return ((int)value);
}
