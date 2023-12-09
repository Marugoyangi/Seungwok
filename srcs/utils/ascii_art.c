/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbpa <jeongbpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:22:59 by jeongbpa          #+#    #+#             */
/*   Updated: 2023/11/28 07:44:14 by jeongbpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_ascii(void);
void	print_ascii1(void);
void	print_ascii2(void);
void	print_ascii3(void);
void	print_ascii4(void);

// void	print_ascii()
// {
// 	printf("\033[1;34m");
// 	printf("╔─────────────────────────╗\n");
// 	printf("│ ╔╦╗╦╔╗╔╦╔═╗╦ ╦╔═╗╦  ╦ ⚡│\n");
// 	printf("│ ║║║║║║║║╚═╗╠═╣║╣ ║  ║   │\n");
// 	printf("│ ╩ ╩╩╝╚╝╩╚═╝╩ ╩╚═╝╩═╝╩═╝ │\n");
// 	printf("╚─────────────────────────╝\n");
// 	printf("\033[0m");
// }

void	print_ascii()
{
	print_ascii1();
	print_ascii2();
	print_ascii3();
	print_ascii4();
	printf("----------------------------=+*#%%@%%%%#*+++++=");
    printf("------------%%      *%%*++-------------------\n");
    printf("-------------------------------==+++++++=---");
    printf("-------------+==#@#*==---------------------\n");
}

void	print_ascii1()
{
	printf("--------------------------------------------");
    printf("----------=+*+=----------------------------\n");
    printf("--------------------------------------------");
    printf("---=+*#+      #+=-----==+++++==------------\n");
    printf("--------------------------------------------");
    printf("=%%%%           #+==*@%%           -@=--------\n");
    printf("-----------------------------------------=@:");
    printf("             .@*       #@@@@@@@  @+=-------\n");
    printf("---------------------------------------*+   ");
    printf("           =:      :@@@@@@@@@#  %%++--------\n");
    printf("------------==---:::-----------------*=     ");
    printf("        -+       #@@@@@@@@@@   @*+=--------\n");
    printf("-------========= ==----------------+*       ");
    printf("      %%        @@@@@@@@@@@   #*+=----------\n");
    printf("----====-.   :====  -------------=%%         ");
    printf("    +       .@@@@@@@@@@+   ##++=-----------\n");
    printf("---===:         =+++=------------#          ");
    printf("  =.      -@@@@@@@@#:   +%%+++=-------------\n");
    printf("--===:   .+++    #%%@@-----------@           ");
    printf(" #      @@@@@@@#    :@%%+++=----------------\n");
    printf("--===   .++*%%@@=-@@@%%----------%%+           ");
    printf("-    *@@@+   .*%%%%#**+++=-------------------\n");
    printf("-==++:   @@@@@+.=@@@+-------*#              ");
    printf("       -*##*++++++===----------------=-----\n");
    printf("-=@@@@.        %%@@@@=-----+*                ");
}

void	print_ascii2()
{
	printf("        *#*+++=--------------=++#%%%%%%%%%%=----\n");
    printf("---#@@@@.     -@@@@%%-----%%                  ");
    printf("          -%%+=----------+%%%%%%%%%%%%%%%%%%%%%%%%%%*----\n");
    printf("-----*@@@@@@@@@@@@%%=---++                   ");
    printf("            %%+=---------=%%%%%%%%%%%%%%%%%%%%%%%%%%%%=---\n");
    printf("-------*@@@@@%%*=------=*                    ");
    printf("            =#+=---------*%%%%%%%%%%#*:+==%%%%*---\n");
    printf("---------------------=%%                     ");
    printf("             @++=--------=%%%%%%: +* +%%.%%%%%%=--\n");
    printf("---------------------*                      ");
    printf("              #++=--------#%%%%#+%%-%%%%%%%%%%%%%%+--\n");
    printf("---------------------# .                    ");
    printf("               @%%+=-------=%%%%%%%%%%%%%%%%%%%%%%%%%%%%--\n");
    printf("--------------------=*                      ");
    printf("               :#++=-------#%%%%%%%%%%%%%%%%%%%%%%#*=-\n");
    printf("--------------------++              @@@#:+  ");
    printf("                 @++-------+%%%%%%%%#+=--------\n");
    printf("-------------------==#  @@:-.      =  .@    ");
    printf("  ==            %%@*+=-------=--------------\n");
    printf("-----------------=---#-#:-%% -. .   =@#@*. ==");
    printf(".               %%+++=----------------------\n");
    printf("------------------==-=+%%*+@* %%@#         .-+");
    printf("=.              #+++-----------------------\n");
    printf("-------------------==+#   : -@@@   .        ");
    printf("               @+++------------------------\n");
}

void	print_ascii3()
{
	printf("-----------------=%%==%%.   -   #    .        ");
    printf("             +#+++=------------:  :--------\n");
    printf("---------------=@%%**=%%--   -%%%%+=+*+#=       ");
    printf("          +@@####*+------------         .--\n");
    printf("---------------=@*--*#%%.   @@*=*@@+=#+      ");
    printf("     #@@@@%%%%*-=::#=   *%%+=-----            \n");
    printf("--------------=@*@*@#--=*@@@++====#@##      ");
    printf(" =*=@=+%%@#--=.=##@@       #---------:   :..\n");
    printf("-------------++..=*.:@---=@-#%%+#=#*==%%    =+");
    printf("#**#=@#**=++**+@%%+#      = %%=------------:.\n");
    printf("-------------@=+=-@++*@---*%%==@+=%%#=%%* =-%%-#");
    printf("++=++-#%%+*-%%=%%##%%==:      #*=--------------\n");
    printf("-------------*@*+##@ = :%%=--%%@*++*@@+@@-%%-%%*");
    printf("*@@@+-++=.*#@@@**+#--+#:  #+=--------------\n");
    printf("-------------=@%%@%%#@%%@  .+=#@@@=.-+##. @-+.=");
    printf("%%*@%%@:=+-#%%*            #*+=---------------\n");
    printf("--------------%%@@%%#%%@@  =+*-*#++:+--+: -%%=+=");
    printf("+*+*+@=+#*@             *+-----------------\n");
    printf("--------------=@@@@@@@  #-=+=%%=*-*==*:  %%#=+");
    printf("*+*+##+-+%%*            **==-----------==---\n");
    printf("---------------*@@@@@@ -@@*+-- =.=::=.  %%@*-");
    printf("**@@@%%+=.=#           :%%%%@*++==-----+%%%%%%=-=\n");
    printf("----------------===+++*+=*%%#%%%%*+:+--=.  :%%#=");
    printf(":==@@#%%:--*@%%+-+#*%%%%#*@      %%*=-+*%%#*%%%%==%%\n");
    printf("---------------------=+*##%%@@@%%#=#+#*+   %%#*");
}

void	print_ascii4()
{
	printf("=-+*%%#+#-++#@@@@@@@@@@@@     .#+-##**##=-+%%\n");
    printf("-------=-==-----==------=+++++%%%%*@*@#*   .@*");
    printf("+::+%%@%%#+.=#@@@@@@@@@@@@%%    :#+-=****+--=%%\n");
    printf("-----=*+-=*=---===------------+#=%%+%%*+    #@");
    printf("--.+@@%%+*%%=*#@@@@@@@@@@@@     #+=---------+\n");
    printf("----=*=--:=+---++-------------+#+%%*%%#+    =*");
    printf("*:=-*@#%%#-#*%%%%@@@@@@@@@@@   %%#++-----------\n");
    printf("---=#*=---=**+**==------------#%%+@*%%#@@@@@@@");
    printf("+*-=+@@@@@@@@@@@@@@@@@@@@.=%%+++--=+**%%+----\n");
    printf("---==-=--==-==--=++=---------=@@#@#@%%@@@@@@@");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@%%+++++--**##%%%%+----\n");
    printf("---=*===-=-=+==-+*=----------=@@@@@@@@@@@@@@");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@*++=---=*#*##+-----\n");
    printf("----++====-+*=--**----------=*@@@@@@@@@@@@@@");
    printf("%%*@@@@@@@@@@@@@@@@@@@@#+@*++-----+++=------\n");
    printf("-------------------------=*=   :-@@@@@@@@@@*");
    printf("++*@@@@@@@@@@@@@@@@@@#-+#*++---------------\n");
    printf("------------------------*: :-  ..+@@@@@@@@*+");
    printf("++++%%@@@@@@@@@@@@@@@+--@%%++=---------------\n");
    printf("------------------------%%    +:----------+@+");
    printf("++=+++*%%@@@@@@@@@%%.---##*++----------------\n");
    printf("------------------------*#-.  =---------*#@+");
    printf("+=--==+++++*%%....:---+#%%++=----------------\n");
    printf("-------------------------=%%-.:*%%%%#%%##+::##++");
    printf("=----------=@+   .*=+##++=-----------------\n");
}
