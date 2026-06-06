import numpy as np

###############################
#        UNIMODAIS          #
###############################


def rosenbrock(X):
    """
    Função de Rosenbrock

    X -> Vetor de entrada

    """
    X = np.array(X)
    if X.ndim > 1:
        return np.sum(
            100 * (X[:, 1:] - X[:, :-1] ** 2) ** 2 + (X[:, :-1] - 1) ** 2, axis=1
        )
    else:
        return np.sum(100 * (X[1:] - X[:-1] ** 2) ** 2 + (X[:-1] - 1) ** 2, axis=0)


def sum_squares(X):
    X = np.asarray(X)

    if X.ndim == 1:
        i = np.arange(1, len(X) + 1)
        return np.sum(i * X**2)

    i = np.arange(1, X.shape[1] + 1)
    return np.sum(i * X**2, axis=1)


def dixon_price(X):
    X = np.asarray(X)

    if X.ndim == 1:
        return (X[0] - 1) ** 2 + np.sum(
            np.arange(2, len(X) + 1) * (2 * X[1:] ** 2 - X[:-1]) ** 2
        )

    return (X[:, 0] - 1) ** 2 + np.sum(
        np.arange(2, X.shape[1] + 1) * (2 * X[:, 1:] ** 2 - X[:, :-1]) ** 2, axis=1
    )


def sphere(X):
    X = np.asarray(X)
    if X.ndim == 1:
        return np.sum(X**2)
    return np.sum(X**2, axis=1)


def zakharov(X):
    X = np.asarray(X)

    if X.ndim == 1:
        i = np.arange(1, len(X) + 1)
        s1 = np.sum(X**2)
        s2 = np.sum(0.5 * i * X)
        return s1 + s2**2 + s2**4

    i = np.arange(1, X.shape[1] + 1)
    s1 = np.sum(X**2, axis=1)
    s2 = np.sum(0.5 * i * X, axis=1)
    return s1 + s2**2 + s2**4


###############################
#        MULTIMODAIS          #
###############################


def ackley(X):
    """
    Função de Ackley

    X -> Vetor de entrada ou população
    """
    X = np.asarray(X)

    # Handle single vector input
    if X.ndim == 1:
        n = X.size
        sum_sq = np.sum(X**2)
        sum_cos = np.sum(np.cos(2 * np.pi * X))
        term1 = -20.0 * np.exp(-0.2 * np.sqrt(sum_sq / n))
        term2 = -np.exp(sum_cos / n)
        return term1 + term2 + 20 + np.e

    # Population input: compute per-row
    n = X.shape[1]
    sum_sq = np.sum(X**2, axis=1)
    sum_cos = np.sum(np.cos(2 * np.pi * X), axis=1)
    term1 = -20.0 * np.exp(-0.2 * np.sqrt(sum_sq / n))
    term2 = -np.exp(sum_cos / n)
    return term1 + term2 + 20 + np.e


def rastrigin(X):
    """
    Função de Rastrigin

    X -> Vetor de entrada ou população
    """
    X = np.array(X)

    if X.ndim > 1:
        n = X.shape[1]
        return 10 * n + np.sum(X**2 - 10 * np.cos(2 * np.pi * X), axis=1)
    else:
        n = len(X)
        return 10 * n + np.sum(X**2 - 10 * np.cos(2 * np.pi * X))


def griewank(X):
    """
    Função de Griewank

    X -> Vetor de entrada ou população
    """
    X = np.asarray(X)

    # Single vector
    if X.ndim == 1:
        d = X.size
        sum_ = np.sum(X**2) / 4000.0
        i = np.arange(1, d + 1)
        cos_ = np.prod(np.cos(X / np.sqrt(i)))
        return sum_ - cos_ + 1.0

    # Population input: compute per-row
    d = X.shape[1]
    sum_ = np.sum(X**2, axis=1) / 4000.0
    i = np.arange(1, d + 1)
    cos_ = np.prod(np.cos(X / np.sqrt(i)), axis=1)
    return sum_ - cos_ + 1.0


def schwefel(X):
    X = np.asarray(X)

    if X.ndim == 1:
        n = len(X)
        return 418.9829 * n - np.sum(X * np.sin(np.sqrt(np.abs(X))))

    n = X.shape[1]

    return 418.9829 * n - np.sum(X * np.sin(np.sqrt(np.abs(X))), axis=1)


def levy(X):
    X = np.asarray(X)

    if X.ndim == 1:
        w = 1 + (X - 1) / 4

        term1 = np.sin(np.pi * w[0]) ** 2

        term2 = np.sum((w[:-1] - 1) ** 2 * (1 + 10 * np.sin(np.pi * w[1:]) ** 2))

        term3 = (w[-1] - 1) ** 2 * (1 + np.sin(2 * np.pi * w[-1]) ** 2)

        return term1 + term2 + term3

    w = 1 + (X - 1) / 4

    term1 = np.sin(np.pi * w[:, 0]) ** 2

    term2 = np.sum(
        (w[:, :-1] - 1) ** 2 * (1 + 10 * np.sin(np.pi * w[:, 1:]) ** 2), axis=1
    )

    term3 = (w[:, -1] - 1) ** 2 * (1 + np.sin(2 * np.pi * w[:, -1]) ** 2)

    return term1 + term2 + term3