# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Chewbacca.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/03 17:52:29 by vbaudin           #+#    #+#              #
#    Updated: 2016/09/03 20:05:25 by vbaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Can Kill Zork Easy !!

.name "Chewie"
.comment "Rrwwgawwrrggawwrr"

save: sti r1, %:live, %1
live: live %1
sti r2, %0, %:save
