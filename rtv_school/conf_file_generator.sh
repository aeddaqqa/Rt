#!/bin/bash

scene_element_options() {

    tput setaf 9;
    echo -e "allowed elements :
    => sphere
    => cylinder
    => cone
    => plane
    => light
    => camera"

    read option

    if [[ ( $option == "sphere" || $option == "cylinder" || $option == "cone" || $option == "plane" || $option == "light" || $option == "camera" ) ]]
    then
    echo "$option" >> ./"$file_name_str".conf
        if [ $option == "sphere" ];
        then
            echo -e "please add its center vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its radius !"
            read -p "radius = " radius
            while [ true ]
            do
                if ! [[ "$radius" =~ ^[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry positive numbers only !"
                    tput setaf 9;
                    read -p "radius = " radius
                else
                break
                fi
            done
            echo -e "$radius" >> ./"$file_name_str".conf
            echo -e "please add its rotation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its translation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its color in Hexadecimal !"
            read -p "color = " color
            echo -e "$color" >> ./"$file_name_str".conf
            echo -e ";" >> ./"$file_name_str".conf
        add_new_element_function
        elif [ $option == "plane" ];
        then
            echo -e "please add its position vector"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its normal vector"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its rotation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its translation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
        #    echo -e "please add its distance !"
        #    read -p "distance = " distance
        #    while [ true ]
        #    do
        #        if ! [[ "$distance" =~ ^[0-9]+\.?[0-9]*$ ]]
        #        then
        #            tput setaf 1;
        #            echo "Sorry positive numbers only !"
        #            tput setaf 9;
        #            read -p "distance = " distance
        #        else
        #        break
        #        fi
        #    done
        #    echo -e "$distance" >> ./"$file_name_str".conf
            echo -e "please add its color in Hexadecimal !"
            read -p "color = " color
            echo -e "$color" >> ./"$file_name_str".conf
            echo -e ";" >> ./"$file_name_str".conf
        add_new_element_function
        elif [ $option == "light" ];
        then
            echo -e "please add its position vector"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its intensity !"
            read -p "intensity = " intensity
            while [ true ]
            do
                if ! [[ "$intensity" =~ ^[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry positive numbers only !"
                    tput setaf 9;
                    read -p "intensity = " intensity
                else
                break
                fi
            done
            echo -e "$intensity" >> ./"$file_name_str".conf
            echo -e "please add its color in Hexadecimal !"
            read -p "color = " color
            echo -e "$color" >> ./"$file_name_str".conf
            echo -e ";" >> ./"$file_name_str".conf
        add_new_element_function
        elif [ $option == "cylinder" ];
        then
            echo -e "please add its position vector"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its radius !"
            read -p "radius = " radius
            while [ true ]
            do
                if ! [[ "$radius" =~ ^[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry positive numbers only !"
                    tput setaf 9;
                    read -p "radius = " radius
                else
                break
                fi
            done
            echo -e "$radius" >> ./"$file_name_str".conf
            echo -e "please add its axis vector"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its rotation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its translation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
        #    echo -e "please add its height !"
        #    read -p "height = " height
        #    while [ true ]
        #    do
        #        if ! [[ "$height" =~ ^[0-9]+\.?[0-9]*$ ]]
        #        then
        #            tput setaf 1;
        #            echo "Sorry positive numbers only !"
        #            tput setaf 9;
        #            read -p "height = " height
        #        else
        #        break
        #        fi
        #    done
        #    echo -e "$height" >> ./"$file_name_str".conf
            echo -e "please add its color in Hexadecimal !"
            read -p "color = " color
            echo -e "$color" >> ./"$file_name_str".conf
            echo -e ";" >> ./"$file_name_str".conf
        add_new_element_function
        elif [ $option == "cone" ];
        then
            echo -e "please add its position vector"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its angle !"
            read -p "angle = " angle
            while [ true ]
            do
                if ! [[ "$angle" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry positive numbers only !"
                    tput setaf 9;
                    read -p "angle = " angle
                else
                break
                fi
            done
            echo -e "$angle" >> ./"$file_name_str".conf
            echo -e "please add its axis vector"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its rotation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its translation vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry number only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
        #    echo -e "please add its radius !"
        #    read -p "radius = " radius
        #    while [ true ]
        #    do
        #        if ! [[ "$radius" =~ ^[0-9]+\.?[0-9]*$ ]]
        #        then
        #            tput setaf 1;
        #            echo "Sorry positive numbers only !"
        #            tput setaf 9;
        #            read -p "radius = " radius
        #        else
        #        break
        #        fi
        #    done
        #    echo -e "$radius" >> ./"$file_name_str".conf
        #    echo -e "please add its height !"
        #    read -p "height = " height
        #    while [ true ]
        #    do
        #        if ! [[ "$height" =~ ^[0-9]+\.?[0-9]*$ ]]
        #        then
        #            tput setaf 1;
        #            echo "Sorry positive numbers only !"
        #            tput setaf 9;
        #            read -p "height = " height
        #        else
        #        break
        #        fi
        #    done
        #    echo -e "$height" >> ./"$file_name_str".conf
            echo -e "please add its color in Hexadecimal !"
            read -p "color = " color
            echo -e "$color" >> ./"$file_name_str".conf
            echo -e ";" >> ./"$file_name_str".conf
        add_new_element_function
        elif [ $option == "camera" ];
        then
            echo -e "please add its position vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its direction vector !"
            read -p "x = " x
            while [ true ]
            do
                if ! [[ "$x" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "x = " x
                else
                break
                fi
            done
            read -p "y = " y
            while [ true ]
            do
                if ! [[ "$y" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "y = " y
                else
                break
                fi
            done
            read -p "z = " z
            while [ true ]
            do
                if ! [[ "$z" =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry numbers only !"
                    tput setaf 9;
                    read -p "z = " z
                else
                break
                fi
            done
            echo -e "$x $y $z" >> ./"$file_name_str".conf
            echo -e "please add its field of view !"
            read -p "field of view = " fov
            while [ true ]
            do
                if ! [[ "$fov" =~ ^[0-9]+\.?[0-9]*$ ]]
                then
                    tput setaf 1;
                    echo "Sorry positive numbers only !"
                    tput setaf 9;
                    read -p "field of view = " fov
                else
                break
                fi
            done
            echo -e "$fov" >> ./"$file_name_str".conf
            echo -e ";" >> ./"$file_name_str".conf
        add_new_element_function
        fi
    else
        tput setaf 1;
        echo "please add one of the allowed elements"
        scene_element_options
    fi
}

file_name_function() {
tput setaf 4;
    read -p "please enter the file name, otherwise press Q to exit : " file_name_str
        if [[ ( "$file_name_str" == "Q" || "$file_name_str" == "q" ) ]]
        then
            exit 0
        elif [[ ! -z "$file_name_str" ]]
        then
        tput setaf 2;
            echo "file name has been accepetd !"
        else
        tput setaf 1;
            echo "file name cannot be empty !"
            file_name_function
        fi
}

add_new_element_function() {

    tput setaf 4;
    read -p "if u want to add another element, please press C, otherwise press Q to exit : " choice
    if [[ ! -z "$choice" ]]
    then
        if [[ ( $choice == C || $choice == c ) ]];
        then
            scene_element_options
        elif [[ ( $choice == Q || $choice == q ) ]];
        then
            length=$(wc -c < "$file_name_str".conf)
            if [ "$length" -ne 0 ] && [ -z "$(tail -c -1 < "$file_name_str".conf)" ]; then
            # The file ends with a newline or null
            dd if=/dev/null of="$file_name_str".conf obs="$((length-3))" seek=1
            exit 0
            fi
        fi
    else
        tput setaf 1;
        echo "wrong argument !"
        add_new_element_function
    fi
}
file_name_function
scene_element_options