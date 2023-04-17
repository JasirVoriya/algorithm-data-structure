class Tools
{
private:
    /* data */
    Tools(/* args */);
    ~Tools();

public:
    static void floyd(void *M, const int MAX_V);
    static int min(int a, int b);
};
void Tools::floyd(void *M, const int MAX_V)
{
    int(*MinDis)[MAX_V] = (int(*)[MAX_V])M;
    for (int k = 0; k < MAX_V; k++)
        for (int i = 0; i < MAX_V; i++)
            for (int j = 0; j < MAX_V; j++)
                MinDis[i][j] = min(MinDis[i][j], MinDis[i][k] + MinDis[k][j]);
}
int Tools::min(int a, int b)
{
    return a < b ? a : b;
}
Tools::Tools(/* args */)
{
}

Tools::~Tools()
{
}
