int kthMissing( std::vector<int> &v, int k, int i, int j)
{
    if ( i == j )
    {
        int missing_count = v[ i ] - i;
        if ( missing_count >= k )
            return v[i] - ( missing_count - k ) - 1;
    }
}
int kthMissing( std::vector<int> &v, int k )
{

}