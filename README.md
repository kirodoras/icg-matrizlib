## Passos para contribuir

### 1. **Faça um Fork do Repositório:**

- Vá para o repositório no github:
  `https://github.com/kirodoras/icg-matrizlib`
- Clique no botão "Fork" no canto superior direito da página para criar uma cópia do repositório na sua própria conta:
<div align="center">
 <img src="./imagens/fork.png">
</div>

### 2. **Clone o Seu Fork Localmente:**

- No seu terminal, clone **seu repositório forked** para o seu ambiente local:
- Exemplo:
  ```bash
  git clone https://github.com/seu-usuario/seu-fork.git
  cd seu-fork
  ```

### 3. **Adicione o Repositório Original como Remoto:**

- Dentro da pasta, adicione o repositório original como um remoto para poder atualizar `git pull`` seu fork com as alterações mais recentes do projeto original:
  ```bash
  git remote add upstream https://github.com/kirodoras/icg-matrizlib
  ```

### 4. **Crie uma Nova Branch para Suas Alterações:**

- Crie e mude para uma nova branch onde você fará suas alterações:
- <i>obs: todos seus commits devem ser feitos nessa branch</i>
  ```bash
  git checkout -b nome-da-sua-branch
  ```

### 5. **Faça Suas Alterações:**

- Faça as alterações necessárias no código.

### 6. **Commit e Push das Alterações:**

- Faça commit das suas alterações e faça push para o seu repositório fork no GitHub:
  ```bash
  git add .
  git commit -m "Descrição curta das alterações"
  git push origin nome-da-sua-branch
  ```

### 7. **Abra um Pull Request:**

- Vá para a página do seu fork no GitHub.
- Clique no botão "Compare & pull request" ao lado da sua nova branch:
<div align="center">
 <img src="./imagens/pr.png">
</div>
- Preencha as informações necessárias e abra o pull request.

### 8. **Aguardar merge no repositorio principal**

## Passos Adicionais

### I. **(Sync) Sempre atualizar o seu Fork:**
- Principalmente antes de criar uma nova funcionalidade.
- Na paǵina do seu fork no github, clique no botão "Sync fork" para atualizar seu fork com as alterações mais recentes do projeto original:
<div align="center">
 <img src="./imagens/sync.png">
</div>

- Após navegue para branch main do fork e faça um pull:
  ```bash
  git checkout main
  git pull
  ```
- Com isso, sua branch main estará atualizada com as alterações mais recentes do projeto original.

### II. **(Branch) Criar uma nova branch para ciclo de implementação `pull request`**
- Evita conflitos

##

Links úteis: 
1. https://gitfichas.com/
2. https://www.hostinger.com.br/tutoriais/git-branch
