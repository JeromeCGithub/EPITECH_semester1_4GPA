char **my_str_to_word_array(char const *str);

int main()
{
    char **test = my_str_to_word_array("");
    char **test2 = my_str_to_word_array("l");
    printf("%s\n", test2[0]);
}
