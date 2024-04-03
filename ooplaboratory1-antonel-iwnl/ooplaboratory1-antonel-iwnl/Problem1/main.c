int main() {
    printf("Input your name and birth year: ");
    char name[100]; 
    int birthYear;
    scanf("%s %d", name, &birthYear);
    printf("Hello %s, you are %d years old", name, 2023 - birthYear);
    return 0;
}

