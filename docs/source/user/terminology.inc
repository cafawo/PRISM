.. _terminology:

Terminology
+++++++++++
Below is a list of the most commonly used terms/abbreviations in *PRISM* and their meaning.
If a term is also a variable within the *PRISM* code, its name is given in brackets.

----

Active emulator system [`active_emul_s`]
    An emulator system that has a data point assigned to it.

Active parameters [`active_par`/`active_par_data`]
    The set of model parameters that are considered to have significant influence on the output of the model and contribute at least one polynomial term to one/the regression function.

Adjusted expectation [`adj_exp`]
    The prior expectation of a parameter set, with the adjustment term taken into account.
    It is equal to the prior expectation if the emulator system has perfect accuracy.

Adjusted values [`adj_val`]
    The adjusted expectation and variance values of a parameter set.

Adjusted variance [`adj_var`]
    The prior variance of a parameter set, with the adjustment term taken into account.
    It is zero if the emulator system has perfect accuracy.

Adjustment term
    The extra term (as determined by the BLA) that is added to the prior expectation and variance values that describes all additional correlation knowledge between model realization samples.

Analysis/Analyze
    The process of evaluating a set of emulator evaluation samples in the last emulator iteration and determining which samples should be used to construct the next iteration.

BLA
    Abbreviation of *Bayes linear approach*.

Construction/Construct
    The process of calculating all necessary components to describe an iteration of the emulator.

Construction check [`ccheck`]
    A list of keywords determining which components of which emulator systems are still required to finish the construction of a specified emulator iteration.

Controller (rank)
    An MPI process that controls the flow of operations in *PRISM* and distributes work to all workers and itself.
    By default, a controller also behaves like a worker, although is not identified as such.

(Inverted) Covariance matrix [`cov_mat`/`cov_mat_inv`]
    The (inverted) matrix of prior covariances between all model realization samples and itself.

Covariance vector [`cov_vec`]
    The vector of prior covariances between all model realization samples and a given parameter set.

Data error [`data_err`]
    The :math:`1\sigma`-confidence interval of a model comparison data point, often a measured/calculated observational error.

Data (point) identifier [`data_idx`]
    The unique identifier of a model comparison data point, often a sequence of integers, floats and strings that describe the operations required to extract it.

Data point [`data_point`]
    A collection of all the details (value, error, space and identifier) about a specific model comparison data point that is used to constrain the model with.

Data (value) space [`data_spc`]
    The value space (linear, logarithmic or exponential) in which a model comparison data point is defined.

Data value [`data_val`]
    The value of a model comparison data point, often an observed/measured value.

Emulation method [`method`]
    The specific method (Gaussian, regression or both) that needs to be used to construct an emulator.

Emulator [`emul`/`emulator`]
    The collection of all emulator systems together, provided by an :obj:`~prism.Emulator` object.

Emulator evaluation samples [`eval_sam_set`]
    The sample set (to be) used for evaluating the emulator.

(Emulator) Iteration [`emul_i`]
    A single, specified step in the construction of the emulator.

Emulator system [`emul_s`]
    The emulated version of a single model output/comparison data point in a single iteration.

Emulator type [`emul_type`]
    The type of emulator that needs to be constructed.
    This is used to make sure different emulator types are not mixed together by accident.

Evaluation/Evaluate
    The process of calculating the adjusted values of a parameter set in all emulator systems starting at the first iteration, determining the corresponding implausibility values and performing an implausibility check.
    This process is repeated in the next iteration if the check was successful and the requested iteration has not been reached.

Evaluation set
    Same as sample set.

External model realization set [`ext_real_set`]
    A set of externally calculated and provided model realization samples and their outputs.

Frozen (active) parameters
    The set of model parameters that, once considered active, will always stay active if possible.

FSLR
    Abbreviation of *forward stepwise linear regression*.

Gaussian correlation length [`l_corr`]
    The maximum distance between two values of a specific model parameter within which the Gaussian contribution to the correlation between the values is still significant.

Gaussian sigma [`sigma`]
    The standard deviation of the Gaussian function.
    It is not required if regression is used.

HDF5
    Abbreviation of *Hierarchical Data Format version 5*.

Implausibility (cut-off) check [`impl_check`]
    The process of determining whether or not a given set of implausibility values satisfy the implausibility cut-offs of a specific emulator iteration.

Implausibility cut-offs [`impl_cut`]
    The maximum implausibility values an evaluated parameter set is allowed to generate, to be considered plausible in a specific emulator iteration.

(Univariate) Implausibility value [`uni_impl_val`]
    The number of sigmas an emulator system expects the (real) model output corresponding to a given parameter set, to be away from the data point it is compared against, given its adjusted values.
    It takes into account all variances associated with the parameter set, which are the observational variance (given by `data_err`), adjusted emulator variance (`adj_var`) and the model discrepancy variance (`md_var`).

Implausibility wildcard
    A maximum implausibility value, preceding the implausibility cut-offs, that is not taken into account during the implausibility cut-off check.
    It is denoted as :math:`0` in provided implausibility cut-off lists.

LHD
    Abbreviation of *Latin-Hypercube design*.

Master (HDF5) file [`hdf5_file`]
    (Path to) The HDF5-file in which all important data about the currently loaded emulator is stored.
    A master file is usually accompanied by several emulator system (HDF5) files, which store emulator system specific data and are externally linked to the master file.

MCMC
    Abbreviation of *Markov chain Monte Carlo*.

Mock data
    The set of comparison data points that has been generated by evaluating the model for a random parameter set and perturbing the output by the model discrepancy variance.

Model
    A `black box` that takes a parameter set, performs a sequence of operations and returns a unique collection of values corresponding to the provided parameter set.

    .. note::
        This is how *PRISM* 'sees' a model, not the used definition of one.

2D model
    A model that has/takes 2 model parameters.

2+D/nD model
    A model that has/takes more than 2 model parameters.

ModelLink (subclass) [`modellink`/`modellink_obj`]
    The user-provided wrapper around the model that needs to be emulated, provided by a :obj:`~prism.modellink.ModelLink` object.

Model discrepancy variance [`md_var`]
    A user-defined value that includes all contributions to the overall variance on a model output that is created/caused by the model itself.
    More information on this can be found in :ref:`md_var`.

Model evaluation samples [`add_sam_set`]
    The sample set (to be) used for evaluating the model.

Model output(s) [`mod_out`/`mod_set`]
    The model output(s) corresponding to a single (set of) model realization/evaluation sample(s).

Model realization samples
    Same as model evaluation samples.

Model realizations (set) [`mod_real_set`]
    The combination of model realization/evaluation samples and their corresponding model outputs.

MPI
    Abbreviation of *Message Passing Interface*.

MPI rank
    An MPI process that is used by any *PRISM* operation, either being a controller or a worker.

MSE
    Abbreviation of *mean squared error*.

OLS
    Abbreviation of *ordinary least-squares*.

Parameter set [`par_set`]
    A single combination/set of model parameter values, used to evaluate the emulator/model once.

Passive parameters
    The set of model parameters that are not considered active, and therefore are considered to not have a significant influence on the output of the model.

(PRISM) Pipeline [`pipe`/`pipeline`]
    The main *PRISM* framework that orchestrates all operations, provided by a :obj:`~prism.Pipeline` object.

Plausible region
    The region of model parameter space that still contains plausible samples.    

Plausible samples [`impl_sam`]
    A subset of a set of emulator evaluation samples that satisfied the implausibility checks.

Polynomial order [`poly_order`]
    Up to which order polynomial terms need to be taken into account for all regression processes.

Potentially active parameters [`pot_active_par`]
    A user-provided set of model parameters that are allowed to become active.
    Any model parameter that is not potentially active will never become active, even if it should.

PRISM
    The acronym for *Probabilistic Regression Instrument for Simulating Models*.
    It is also a one-word description of what *PRISM* does (splitting up a model into individually emulated model outputs).

PRISM (parameters) file [`prism_file`]
    (Path to) The text-file that contains non-default values for the :ref:`parameters` that need to be used for the currently used :obj:`~prism.Pipeline` instance.
    It is :pycode:`None` if no such file is used.

Prior covariance [`prior_cov`]
    The covariance value between two parameter sets as determined by an emulator system.

Prior expectation [`prior_exp`]
    The expectation value of a parameter set as determined by an emulator system, without taking the adjustment term (from the BLA) into account.
    It is a measure of how much information is captured by an emulator system.
    It is zero if regression is not used, as no information is captured.

Prior variance [`prior_var`]
    The variance value of a parameter set as determined by an emulator system, without taking the adjustment term (from the BLA) into account.

Projection/Project
    The process of analyzing a specific set of active parameters in an iteration to determine the correlation between the parameters.

Projection figure
    The visual representation of a projection.

Regression
    The process of determining the important polynomial terms of the active parameters and their coefficients, by using an FSLR algorithm.

Regression covariance(s) [`poly_coef_cov`]
    The covariances between all polynomial coefficients of the regression function.
    By default, they are not calculated and it is empty if regression is not used.

Residual variance [`rsdl_var`]
    The variance that has not been captured during the regression process.
    It is empty if regression is not used.

Root directory [`root_dir`]
    (Path to) The directory/folder on the current machine in which all *PRISM* working directories are located.
    It also acts as the base for all relative paths.

Sample [`sam`]
    Same as a parameter set.

Sample set [`sam_set`]
    A set of samples.

Worker (rank)
    An MPI process that receives its calls/orders from a controller and performs the heavy-duty operations in *PRISM*.

Working directory [`working_dir`]
    (Path to) The directory/folder on the current machine in which the *PRISM* master file, log-file and all projection figures of the currently loaded emulator are stored.

Worker mode [`worker_mode`]
    A mode initialized by :attr:`~prism.Pipeline.worker_mode`, where all workers are continuously listening for calls made by the controller rank and execute the received messages.
    This allows for serial codes to be combined more easily with *PRISM*.
    See :ref:`dual_nature` for more information.