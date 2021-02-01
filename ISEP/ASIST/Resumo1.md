# ASIST

## Administrador Sistemas

* Instalação do sistema e infraestrutura
* Manutenção
* Planear, Implementar e verificar
  * Infrastrutura
  * Aplicações do sistema
  * Requisitos de segurança

  * Novas tecnologias
  * Requisitos Legais
* Otimizar tráfico
* Deve haver apenas um administrador de sistemas
  * Responsabilidade não pode ser repartida
  * Supervisiona todos os recursos humanos orientados a
    * Infraestrutura
    * Sistemas
    * Segurança
  * **Único e exclusivo** responsavel pelo bom funcionamento de tudo
* Formar e treinar equipa
* Planear backup plan de salvaguarda (DRP)
* Definir critérios de gestão de utilizadores
* Assegurar suporte técnico utilizadores
* Atualização sistemas
* Automatizar e validar estas tarefas e a sua execução
* Documentar os sistemas e infraestrutura
* Relatórios de constrangimentos que possam surgir
* Prever mecanismos necessários á mitigação ou eliminação de dados

### Centro Processamento de Dados (CPD)

* Local onde se encontram os sistemas e equipamentos da infraestrutura
* Vantagens
  * Estão assegurados critérios ambientais
    * Temperatura
    * Humidade
    * Poeira
  * Alternativas de alimentação elétrica em caso de falha
  * Piso falso ou teto falso para cablagens
  * Armários apropriados para equipamento
  * Segurança Anti-incêndios
* Desvantagens
  * Custos operacionais crescem rápido em função de equipamentos em atividade
  * Área ocupada custa dinheiro
  * Quanto mais novas tecnologias, maiores os custos
* Custos energéticos são causados por:
  * Aumento de quantidade de equipamentos que leva a
  * Aumento da necessidade de refrigeração
* Para reduzir os custos operacionais:
  * Evitar reduzir os custos energéticos, reduzindo ao máximo o número de equipamentos necessários
  
1. A regra habitual é adicionar novos servidores em vez de utilizar os que já existem para evitar estragar o que funciona
2. Embora os servidores muitas vezes tem uma baixa taxa de utilização
3. Para isto os servidores são virtualizados

### Servidores Virtuais

* Permite a utilização de um só servidor fisico mais potente que contem um *hospedeiro de virtualização*
* O Hospedeiro tem vários servidores virtuais configurados
  * Designados por convidados
* Cada convidado necessita do seu OS e reserva de caracteristicas distribuidos de maneira dinâmica
  * Disco
  * Memória
  * Placa de Rede
* Convidados são totalmente independentes entre si
* Virtualização ainda tem custos embora não crescam da mesma forma que os custos dos servidores fisicos
* As configurações de cada servidor virtual são definidas por configuração
* Facilita a produção em sério de convidados com as mesmas caracteristicas
* Facilita cópias de segurança(snapshots)

#### Inconvenientes

* Single point of failure (if it fails rip everything)
  * Pode ser resolvido através da redundância de hospedeiros
* Falha de planeamento no tamanho do servidor hospedeiro e vai haver problemas de desempenho nos convidados
* Cada convidado necessita de uma licença de Sistema Operativo independente do anfitrião
  * Pode ser considerado um positivo pois um hospedeiro windows poderá ter convidado Linux
* Caso seja pretendido utilizar o mesmo OS em todos os convidados é melhor utilizar containers

### Containers

* São parecidos com servidores virtuais no entanto partilham o Sistema Operativo e bibliotecas
* Exige menos recursos fisicos a correr múltiplos OS e por isso é mais eficaz
* Não permite OS diferentes entre hospedeiro e convidados
* Problemas de segurança caso o hospedeiro ou convidado, forem infetados por malware
* SPF(Single point of failure)

### Localização de Dados

* Cada sistema possui o seu próprio armazenamento **Direct Attached Storage(DAS)**
  * Contem o sistema operativo, aplicações e dados
  * Apresenta-se como um block device
  * Acesso exclusivo do sistema a que está ligado é um inconveniente
  * Adição ou Remoção de um dispositivo de armazenamento implica uma intervenção fisica
    *  Muitas vezes é necessário a desativação do sistema temporariamente
  * Salvaguarda de dados é executada pelo sistema, consumindo recursos
  * Não há economia de escala para partilha de armazenamento
* Utilização de um **Network Attached Storage (NAS)**
  * Apresenta-se como um file system ao OS
  * Vantagens:
    * Económico de facultar espaço de armezanamento a vários sistemas/utilziadores
    * Rápido instalar e configurar
    * Suporta niveis de **RAID (Redundant Access of Independent Disks)**
    * Definição permissões pastas ficheiros
    * Elevada utilização de recursos
  * Desvantagens:
    * Ocupa recursos de rede (Ocupa pelo menos 1 IP)
    * Latência e problemas de transferência de dados
    * Desempenho é afetado pela disponibilidade de rede
* Utilização de um **Storage Area Network (SAN)**
  * Designado de **virtualização de storage**
    * Porque não está fisicamente ligado a cada sistema
  * Sistema armazenamento proporciona discos lógicos **Logical Units (LUN)**
    * Disco lógico é acedido da mesma forma que um disco local
  * Gestão e armazenamento é efetuado por aplicações
    * Não necessita paragem de equipamentos
  * Permite a criação de
    * Snapshots
    * Clonagem
    * Sincronização
  * Mais dispendioso
  * Maior capacidade
  * Rede própria fisicamente distinta para maior desempenho
  * Elevada fiabilidade e segurança
  * Idealmente é suportada por uma tecnologia **Fibre Channel (FC)**
  * Deverá existir redundância de ligações na SAN
  * Há 2 protocolos e várias implementações de SAN
    * Protocolo FC
      * Fibre Channel Protocol (FCP)
        * Possui 4 camadas
          * FC-4
            * Define as interfaces de aplicação e o mapeamento para niveis mais baixos
          * FC-2
            * Nivel de transporte
            * Endereços Origem e Destino
          * FC-1
            * Protocolo Transmissão
            * Inclui Regras Codificação e Descodificação, controlo de erros
          * FC-0
            * Nivel fisico
      * Fibre Channel Over IP(FCIP)
        * Mais recente
        * Implementado ao nivel da SAN
        * Nao consegue conectar diretamente com uma SAN iFCP
        * Tira partido do TCP/IP
      * Internet Fibre Channel Protocol (iFCP)
        * Mais recente
        * Implementado ao nivel do dispositivo
        * Nao consegue conectar diretamente com uma SAN FCIP
        * Tira partido do TCP/IP
      * Fibre Channel over Ethernet (FCoE)
      * Implica a existência de equipamentos fisicos para interligação com estrutura informática
        * **Host Bus Adapter(HBA)** liga sistema a dispositivos de tecnologia não nativa
        * **Converged Network Adapter(CNA)** (para interligar FCoE) contem em simultaneo uma interface HBA e uma interface de rede
        * Switch/Gateway FC
      * Ligações fisicas variadas, **core edge** como uma opçao
    * Protocolo 2
      * Internet Small Computer System Interface (iSCSI)
        * Alternativa mais económica
        * Nativo de sistemas operativos modernos
          * Não necessita de placas ou equipamentos externos
        * Interconexão de SAN remotas
        * Tira partido de TCP/IP
        * Possui um software initiator e um software target
  * Necessitam de:
    * Permitir interconexão
    * Ser escalavel
    * Ser simples de gerir

### Redundant Array of Independent Disks (RAID)

* Replicam em tempo real um disco para o outro
* Expandem a sua capacidade através de utilizaçao de multiplos discos
* Há varios niveis de RAID identificados por número, mas são divididos por um principio base:
  * Por software (suportado diretamento pelos SO's mais recentes)
    * RAID 0
      * Striping
      * 2 ou mais discos que o Sistema Operativo interpreta como sendo um único espaço armazenamento
      * Vantagem o aumento de espaço e armazenamento e desempenho
      * Perda de informação se qualquer um dos erros se danifica
    * RAID 1
      * Mirroring
        * Qualquer coisa escrita num disco é replicado noutro
        * Diminuição da probabilidade de perda de informação
        * Lê mais rápido mas grava mais lento
        * Os discos tem de ter a mesma dimensão
    * RAID 5
      * Striping with parity
      * Exige um minimo 3 discos
      * Dados gravados em dois discos e terceiro armazena paridade
      * 75% do espaço serve para armazenar dados (good)
      * Lê mais rápido mas grava mais lento
      * Capacidade é o tamanho do disco mais pequeno vezes o número discos menos um
    * RAID 10 (RAID 1 + 0)
      * Striping with mirroring
      * Uma junção do RAID 0 e RAID 1
      * Todas as vantagens e desvantagens do RAID 0 e RAID 1
      * Capacidade máxima é o tamanho RAID 0 associado
  * Por hardware (exige um controlador específico)
    * RAID 2
      * Striping ao nível de bit
    * RAID 3
      * Striping ao nível de byte com paridade dedicada
    * RAID 4
      * Striping ao nível de bloco com paridade dedicada
    * RAID 6
      * Equivalente ao RAID 5
      * Tem dupla paridade distribuída
      * Permite recuperar a informação em caso de dano em dois dos discos
    * RAID 50
      * Exige um mínimo de 4 discos
    * RAID 60
      * Exige um mínimo de 8 discos







