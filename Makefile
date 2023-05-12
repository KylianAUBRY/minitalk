NAMESERVER	=	server

NAMECLIENT	=	client

SERVER = server.c	\
			utils/ft_put.c \

CLIENT = client.c	\
			utils/ft_put.c \

OBJ_SERVER = ${SERVER:.c=.o}

OBJ_CLIENT = ${CLIENT:.c=.o}

CC =	cc

CFLAGS	=	-Wall -Wextra -Werror -g

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:  ${NAMESERVER} ${NAMECLIENT}

$(NAMESERVER): ${OBJ_SERVER}
		$(CC) ${OBJ_SERVER} -o $(NAMESERVER)

${NAMECLIENT}:${OBJ_CLIENT}
		$(CC) ${OBJ_CLIENT} -o $(NAMECLIENT)

clean:
		rm -f ${OBJ_SERVER} ${OBJ_CLIENT}

fclean:	clean
		rm -f $(NAMESERVER) ${NAMECLIENT}

re:	fclean all

.PHONY: all clean fclean re