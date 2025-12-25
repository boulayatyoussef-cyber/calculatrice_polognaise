# 🧮 Mini-Calculatrice Polonaise (Prefix Notation)

[![C Language](https://img.shields.io/badge/Language-C-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Ce projet est une implémentation en **C** d'une mini-calculatrice utilisant la **notation polonaise** (ou notation préfixée), proposée en 1924 par Jan Łukasiewicz.

Dans ce système, les opérateurs précèdent leurs opérandes. Cela permet d'écrire des expressions complexes sans jamais utiliser de parenthèses.

---

## 🌳 Concept Mathématique

L'expression est analysée comme un arbre de syntaxe abstrait (AST). Par exemple, l'expression `+ 3 * 4 2` représente :



| Notation Polonaise | Notation Classique | Résultat |
| :--- | :--- | :--- |
| `+ 8 3` | $8 + 3$ | **11** |
| `+ 3 * 4 2` | $3 + (4 \times 2)$ | **11** |
| `* + 3 4 2` | $(3 + 4) \times 2$ | **14** |

---

## 🛠️ Fonctionnalités

- **Analyse Récursive** : Utilisation d'une descente récursive pour évaluer les expressions.
- **Gestion des Erreurs** : Détection des expressions mal formées ou incomplètes.
- **Générateur Aléatoire** : Commande intégrée pour générer des additions valant un nombre spécifique.
- **REPL Interactif** : Interface en ligne de commande pour des calculs rapides.

---

## 🚀 Installation et Compilation

1. **Cloner le dépôt** :
   ```bash
   git clone [https://github.com/votre-utilisateur/prefix-calculator.git](https://github.com/votre-utilisateur/prefix-calculator.git)
   cd prefix-calculator
