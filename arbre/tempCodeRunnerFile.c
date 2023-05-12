struct noeud* supprimer(struct noeud*test,int x)

{
    if(test==NULL) return NULL;
    if(test->sad==NULL && test->sag==NULL)
    {
        free(test);
        return NULL;
    }
    if(x>test->info)
    {
        test->sad=supprimer(test->sad,x);
    }
    else if(x<test->info)
        test->sag=supprimer(test->sag,x);
    else
    {
        if(test->sad)
        {
            test->info=test->sad->info;
            test->sad=supprimer(test->sad,test->sad->info);
        }else if(test->sag)
        {
            test->info=test->sag->info;
            test->sag=supprimer(test->sag,test->sag->info);

        }
    }
    return test;

}