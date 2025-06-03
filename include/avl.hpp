#pragma once
#include <utility>
#include <vector>
#include <cstdlib>

/**
 * @brief Classe que representa uma Árvore Binária de Busca (BST).
 *
 * Armazena elementos em ordem, permitindo operações eficientes de busca,
 * inserção e remoção.
 *
 * @tparam T Tipo dos elementos armazenados na árvore.
 */
template <class T>
class AVL {
 private:
  /**
   * @brief Estrutura interna que representa um nó da árvore.
   */
  struct TreeNode {
    T data;           ///< Valor armazenado no nó.
    TreeNode* left;   ///< Ponteiro para o filho à esquerda.
    TreeNode* right;  ///< Ponteiro para o filho à direita.
    int height;  ///< Altura do nó na árvore. Usada para balanceamento da AVL.

    /**
     * @brief Construtor que inicializa o nó com um valor.
     *
     * @param value Valor a ser armazenado no nó.
     */
    TreeNode(const T& value);

    /**
     * @brief Destrutor do nó, libera recursivamente seus filhos.
     */
    ~TreeNode();

    /**
     * @brief Retorna o nó com o maior valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor máximo.
     */
    TreeNode* max();

    /**
     * @brief Retorna o nó com o menor valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor mínimo.
     */
    TreeNode* min();
  };

  /**
   * @brief Retorna a altura de um nó da árvore.
   *
   * @param node Ponteiro para o nó.
   * @return Altura do nó se não for nulo, ou -1 caso seja nullptr.
   */
  int height(TreeNode* node) const;

  /**
   * @brief Atualiza o balanceamento da árvore AVL a partir de um nó.
   *
   * Recalcula a altura do nó, verifica o fator de balanceamento
   * e realiza rotações simples ou duplas conforme necessário para
   * manter as propriedades da AVL.
   *
   * @param node Referência para o ponteiro do nó a ser balanceado.
   */
  void balance(TreeNode*& node);

  /**
   * @brief Insere um valor na árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser inserido.
   * @return `true` se a inserção foi bem-sucedida, `false` se o valor já
   * existia.
   */
  bool insert(TreeNode*& node, const T& value);

  /**
   * @brief Remove um valor da árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser removido.
   * @return `true` se a remoção foi bem-sucedida, `false` se o valor não foi
   * encontrado.
   */
  bool remove(TreeNode*& node, const T& value);

  /**
   * @brief Verifica se a árvore contém um valor específico.
   *
   * @param node Ponteiro para o nó atual.
   * @param value Valor a ser buscado.
   * @return `true` se o valor estiver na árvore, `false` caso contrário.
   */
  bool contain(const TreeNode* const node, const T& value) const;

  /**
   * @brief Executa a travessia in-order recursiva.
   *
   * Visita a subárvore esquerda, depois o nó atual e em seguida a subárvore
   * direita. Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void in_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia pre-order recursiva.
   *
   * Visita o nó atual, em seguida a subárvore esquerda e depois a direita.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void pre_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia post-order recursiva.
   *
   * Visita a subárvore esquerda, depois a direita e por último o nó atual.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void post_order(const TreeNode* const node, std::vector<T>& result) const;

 public:
  /**
   * @brief Construtor da árvore (inicialmente vazia).
   */
  AVL();

  /**
   * @brief Destrutor da árvore, libera todos os nós.
   */
  ~AVL();

  /**
   * @brief Insere um novo valor na árvore.
   *
   * @param value Valor a ser inserido.
   * @return `true` se inserido com sucesso, `false` se o valor já existia.
   */
  bool insert(const T& value);

  /**
   * @brief Remove um valor da árvore.
   *
   * @param value Valor a ser removido.
   * @return `true` se o valor foi removido, `false` se não estava presente.
   */
  bool remove(const T& value);

  /**
   * @brief Verifica se um valor está presente na árvore.
   *
   * @param value Valor a ser verificado.
   * @return `true` se presente, `false` caso contrário.
   */
  bool contain(const T& value) const;

  /**
   * @brief Retorna os valores da árvore em ordem (in-order).
   *
   * Visita a subárvore esquerda, o nó atual e a subárvore direita.
   *
   * @return Vetor com os valores em ordem.
   */
  std::vector<T> in_order() const;

  /**
   * @brief Retorna os valores da árvore em pré-ordem (pre-order).
   *
   * Visita o nó atual, depois a subárvore esquerda e depois a direita.
   *
   * @return Vetor com os valores em pré-ordem.
   */
  std::vector<T> pre_order() const;

  /**
   * @brief Retorna os valores da árvore em pós-ordem (post-order).
   *
   * Visita a subárvore esquerda, depois a direita e por fim o nó atual.
   *
   * @return Vetor com os valores em pós-ordem.
   */
  std::vector<T> post_order() const;

  /**
   * @brief Verifica se a árvore está balanceada (propriedade da AVL).
   *
   * @return `true` se todos os nós estão balanceados, `false` caso contrário.
   */
  bool is_balanced() const { return is_balanced(root).first; }

  /**
   * @brief Verifica recursivamente se a subárvore está balanceada e retorna sua
   * altura.
   *
   * @param node Nó atual.
   * @return Par (está_balanceada, altura).
   */
  std::pair<bool, int> is_balanced(TreeNode* node) const {
    if (!node) return {true, -1};

    auto left = is_balanced(node->left);
    auto right = is_balanced(node->right);

    bool balanced =
        left.first && right.first && std::abs(left.second - right.second) <= 1;
    int node_height = 1 + std::max(left.second, right.second);

    return {balanced, node_height};
  }

 private:
  TreeNode* root;  ///< Ponteiro para a raiz da árvore.
};

template <class T>
int AVL<T>::height(TreeNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return 1 + std::max(height(node->left), height(node->right));
}

template <class T>
void AVL<T>::balance(TreeNode*& node) {
  if (node == NULL) {
    return; 
  }
  
  int balance_factor = height(node->left) - height(node->right);

  if (balance_factor > 1) {
    if (height(node->left->right) > height(node->left->left)) {
      TreeNode* leftChild = node->left;
      TreeNode* lrChild = leftChild->right;

      leftChild->right = lrChild->left;
      lrChild->left = leftChild;

      node->left = lrChild;
    }

    TreeNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;

    node->height = height(node);
    temp->height = height(temp);

    node = temp;
  }
  else if (balance_factor < -1) {
    if (height(node->right->left) > height(node->right->right)) {
      TreeNode* rightChild = node->right;
      TreeNode* rlChild = rightChild->left;

      rightChild->left = rlChild->right;
      rlChild->right = rightChild;

      node->right = rlChild;
    }

    TreeNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;

    node->height = height(node);
    temp->height = height(temp);

    node = temp;
  }
  else {
    node->height = height(node);
  }
}

template <class T>
AVL<T>::TreeNode::TreeNode(const T& value) : data{value}, left{NULL}, right{NULL} {}

template <class T>
AVL<T>::TreeNode::~TreeNode() {
  if (left != NULL) {
    delete left;
    left = NULL;
  }
  if (right != NULL) {
    delete right;
    right = NULL;
  }
}

template <class T>
typename AVL<T>::TreeNode* AVL<T>::TreeNode::max() {
  if (right != NULL) {
    return right->max();
  }
  else 
    return this;
}

template <class T>
typename AVL<T>::TreeNode* AVL<T>::TreeNode::min() {
  if (left != NULL) {
    return left->min();
  }
  else 
    return this;
}

template <class T>
AVL<T>::AVL() : root{NULL} {}

template <class T>
AVL<T>::~AVL() {
  delete root;
}

template <class T>
bool AVL<T>::insert(const T& value) {
  return insert(root, value);
}

template <class T>
bool AVL<T>::remove(const T& value) {
  return remove(root, value);
}

template <class T>
bool AVL<T>::contain(const T& value) const {
  return contain(root, value);
}

template <class T>
bool AVL<T>::insert(TreeNode*& node, const T& value) {
  if (node == NULL) {
    node = new TreeNode(value);
    return true; 
  }
  if (value < node->data) {
    bool inserted = insert(node->left, value);
    if (inserted) balance(node);
    return inserted;
  }
  if (node->data < value) {
    bool inserted = insert(node->right, value);
    if (inserted) balance(node);
    return inserted;
  }
  return false;
}

template <class T>
bool AVL<T>::contain(const TreeNode* const node, const T& value) const {
  if (node == NULL) {
    return false;
  } 
  if (!(value < node->data) && !(node->data < value)) {
    return true;
  } else if (value < node->data) {
    return contain(node->left, value);
  } else {
    return contain(node->right, value);
  }
}

template <class T>
bool AVL<T>::remove(TreeNode*& node, const T& value) {
  if (node == NULL) {
    return false;
  }
  bool removed = false;
  if (value < node->data) {
    removed = remove(node->left, value);
    if (removed) balance(node);
  } else if (node->data < value) {
    removed = remove(node->right, value);
    if (removed) balance(node);
  } else {
    // nó encontrado
    removed = true;
    if (node->left == NULL && node->right == NULL) {
      delete node;
      node = NULL;
    } else if (node->left == NULL) {
      TreeNode* temp = node;
      node = node->right;
      temp->right = NULL;
      delete temp;
    } else if (node->right == NULL) {
      TreeNode* temp = node;
      node = node->left;
      temp->left = NULL;
      delete temp;
    } else {
      TreeNode* sucessor = node->right->min();
      node->data = sucessor->data;
      removed = remove(node->right, sucessor->data);
      if (removed) balance(node);
    }
  }
  return removed;
}

template <class T>
void AVL<T>::in_order(const TreeNode* const node, std::vector<T>& result) const {
   if(node->left) {
    in_order(node->left, result);
  }
  result.push_back(node->data);
  if (node->right) {
    in_order(node->right, result);
  }
}

template <class T>
std::vector<T> AVL<T>::in_order() const {
  std::vector<T> result;
  in_order(root, result);
  return result;
}

template <class T>
void AVL<T>::pre_order(const TreeNode* const node, std::vector<T>& result) const {
  result.push_back(node->data);
  if(node->left) {
    pre_order(node->left, result);
  }
  if(node->right) {
    pre_order(node->right, result);
  }
}

template <class T>
std::vector<T> AVL<T>::pre_order() const {
  std::vector<T> result;
  pre_order(root, result);
  return result;
}

template <class T>
void AVL<T>::post_order(const TreeNode* const node, std::vector<T>& result) const {
  if (node->left) {
    post_order(node->left, result);
  }
  if(node->right) {
    post_order(node->right, result);
  }
  result.push_back(node->data);
}

template <class T>
std::vector<T> AVL<T>::post_order() const {
  std::vector<T> result;
  post_order(root, result);
  return result;
}
