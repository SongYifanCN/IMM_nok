#define HEAD_INFO

#include "sfmt/SFMT.h"
#include "head.h" 

class Argument{
public:
    int k;
    string dataset;
    double epsilon;
    double epsilon1;
    string model;
    double T;
    bool truncated=false;
    int rand_seed=2023;
};

#include "graph.h"
#include "infgraph.h"
#include "imm.h"



void run_with_parameter(InfGraph &g, Argument & arg, int64 num_RRsets=50000)
{
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << arg.dataset << " k=" << arg.k << " epsilon=" << arg.epsilon <<   " " << arg.model << " " << arg.epsilon1 << endl;
        double total_eps = arg.epsilon + arg.epsilon1;
        string folder_name =  arg.dataset.substr(0, arg.dataset.size()-1) + "_k_" + to_string(arg.k) + "_eps_" + to_string(total_eps) + "_rand_" +to_string(arg.rand_seed);
        string folder_path = "./exp_data/" + folder_name + "/";
        cout << folder_path << endl;
        make_dir(folder_path);
        string log_file_name;
        if (arg.truncated)
        {
            log_file_name = "eps_" + to_string(arg.epsilon) + "_eps1_" + to_string(arg.epsilon1) + ".txt";
        }
        else log_file_name = "no_trunc.txt";
        string log_filepath = folder_path + log_file_name;
        ofstream logfile(log_filepath);
        
        Imm::InfluenceMaximize(g, arg);

        INFO(g.seedSet);
        arg.truncated = false;
        INFO("Influence:");
        double eval_inf = g.comp_inf_by_cov(num_RRsets, arg);
        INFO(eval_inf);
    logfile << "Influence Evaluation: " << eval_inf << endl;
    Timer::show(logfile);
}
void Run(int argn, char **argv)
{
    Argument arg;

    for (int i = 0; i < argn; i++)
    {
        if (argv[i] == string("-help") || argv[i] == string("--help") || argn == 1)
        {
            cout << "./tim -dataset *** -epsilon *** -k ***  -model IC|LT|TR|CONT " << endl;
            return ;
        }
        if (argv[i] == string("-dataset")) 
            arg.dataset = argv[i + 1];
        if (argv[i] == string("-epsilon")) 
            arg.epsilon = atof(argv[i + 1]);
        if (argv[i] == string("-epsilon1")) 
            arg.epsilon1 = atof(argv[i + 1]);
        if (argv[i] == string("-T")) 
            arg.T = atof(argv[i + 1]);
        if (argv[i] == string("-k")) 
            arg.k = atoi(argv[i + 1]);
        if (argv[i] == string("-RAND_SEED")) 
            arg.rand_seed = atoi(argv[i + 1]);
        if (argv[i] == string("-model"))
            arg.model = argv[i + 1];
        if (argv[i] == string("-truncated"))
        {
            string str_trunc = argv[i + 1];
            arg.truncated = stob(str_trunc);
        }
            
    }
    ASSERT(arg.dataset != "");
    ASSERT(arg.model == "IC" || arg.model == "LT" || arg.model == "TR" || arg.model=="CONT");

    string graph_file;
    if (arg.model == "IC")
        graph_file = arg.dataset + "graph_ic.inf";
    else if (arg.model == "LT")
        graph_file = arg.dataset + "graph_lt.inf";
    else if (arg.model == "TR")
        graph_file = arg.dataset + "graph_tr.inf";
    else if (arg.model == "CONT")
        graph_file = arg.dataset + "graph_cont.inf";
    else
        ASSERT(false);

    InfGraph g(arg.dataset, graph_file);


    if (arg.model == "IC")
        g.setInfuModel(InfGraph::IC);
    else if (arg.model == "LT")
        g.setInfuModel(InfGraph::LT);
    else if (arg.model == "TR")
        g.setInfuModel(InfGraph::IC);
    else if (arg.model == "CONT")
        g.setInfuModel(InfGraph::CONT);
    else
        ASSERT(false);

    //INFO(arg.T);

    run_with_parameter(g, arg);
}


int main(int argn, char **argv)
{
    __head_version = "v1";
    OutputInfo info(argn, argv);


    Run( argn, argv );
}


