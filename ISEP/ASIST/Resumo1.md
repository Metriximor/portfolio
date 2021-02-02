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
    * Muitas vezes é necessário a desativação do sistema temporariamente
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

## Business Continuity Management (BCM)

* Impacto de recursos informáticos é diferente de particular para empresas
* ISO 27000, apoiado por ISO 22301 e 22313 definem critérios para manter a continuidade de negócio
  * São regras escalaveis para organizações
  * Normalizam metodologias e possibilitam critérios comuns
  * É uma metodologia top-down
* É sempre possivel arranjar uma estratégia para assegurar a continuidade do negócio
  * Algumas estratégias têem um risco demasiado elevado para os beneficios
  * **Asset Value (AV)** representa o valor do item em causa
  * Exposição ao risco desse item é **Exposure Factor (EF)**
  * **Single Loss Expenditure SLE** é obtido pela multiplicação
    * SLE = AV * EF
    * Pode ser calculado ao longo de um ano para um bem
      * **ALE Annualized Loss of Expectancy**
      * **ARO Annualized Rate of Occurrence**
      * ALE = SLE \* ARO = AV \* EF * ARO
      * Valor obtido deve ser comparado com o custo da ação para mitigar
* Prevenção perda de dados:
  * Mirroring para instalações remotas
    * Pode ser sync ou async (Synchronous Mirroring)
    * Facilita a recuperação em caso de desastre
    * RPO e WRT são nulos(sync) ou prox disso(async)
    * Implica a necessidade de confidencialidade e integridade de dados
      * Maior latência na rede
      * Impacto indireto no SLA
  * Cópias de segurança
    * 3 estratégias
      * Integral/completa
        * copia tudo
        * maior tempo de cópia(prejudica RPO)
        * menor tempo de reposição(beneficia WRT)
      * Incremental
        * necessita de uma cópia integral/Completa prévia
        * copia os dados que foram alterados da ultima copia incremental
      * Diferencial
        * necessita de uma cópia integral/completa prévia
        * copia os dados que foram alterados da cópia integral
    * Deve ser sempre feito em duplicado
    * Deve ser guardada num local remoto
    * Deve ser verificada aleatoriamente a cópia e a capacidade de reposição de dados

### Plan-Do-Check-Act (PDCA)

* É um modelo de continua observação. planeamento e ação
* Integra um conjunto de critérios que devem ser cumpridos
* Deve analizar e mitigar constrangimentos potenciais
* Todas as ameaças devem ser eliminadas/mitigadas
* Critérios I
  * **Maximum Tolerable Period of Disruption (MTPD)**
    * tempo máximo de desempenho inferior aos requisitos da infreaestrutura informática
  * **Maximum Tolerable Downtime (MTD)**
    * tempo máximo de inoperabilidade da infraestrutura informática
  * o objetivo é retomar a operação da empresa num periodo inferior definidos nestes critérios
  * valores podem não ser fixos, dinâmicos
    * periodos mais exigentes - negócios sazonais
    * pode haver serviços mais urgentes
    * O BCM deve especificar todos os aplicáveis
* Critérios II
  * **Minimum Business Continuity Objective (MBCO)**
  * Especificar nivel minimo operacionalidade que deve ser mantida durante uma disrupção na infraestrutura
  * MTD/MTPD é mais restrito para serviços associados a este objetivo
  * nivel minimo que é aceite e pretendido pela organização
  * Designa-se de conjunto de parâmetros qualitativos e quantitativos **Service Level Agreement (SLA)**
    * deve contemplar não apenas os niveis de serviço
      * confidencialidade
      * integridade
      * disponibilidade
    * deve especificar forma de medir e validar niveis de serviço
    * sistema que cumpre SLA combinado é designado por **Sistema seguro**
* Critérios III
  * **Businness Impact Analysis (BIA)**
    * identifica atividades criticas da organizacao e dependencias
    * prioritiza as operações de recuperação após disrupção
  * **Risk Assessment (RA)**
    * cenários que podem afetar continuidade do negócio
    * probabilidade de cenários ocorrerem
    * impacto dos cenários
    * representado por matriz de risco
    * risco = impacto * probabilidade
      * probabilidade [1 a 5](menos a mais provavel)
      * impacto [1 a 4] (marginal a catastrófico)
    * deve ser definido para todos os riscos identificados
    * matriz de risco não é obrigatória mas recomendada
  * **Business Continuity Plan (BCP)**
    * parte integrante do BCM
    * documenta procedimentos a efetuar para
      * responder
      * recuperar
      * retomar
      * restaurar
  * **Disaster Recovery Plan (DRP)**
    * parte integrante do BCM
    * DRP é acionado quando o MBCO ou MTD são violados
    * **Recovery Time Objective (RTO)**
      * tempo médio de recuperação dos sistemas e infraestruturas
      * pode ser independente da estratégia adotada
    * **Recovery Point Objective (RPO)**
      * tempo máximo de perda de dados aceite
    * **Work Recovery Time (WRT)**
      * tempo necessário para repor os dados e aplicações e testa-los
      * é influenciado pela estratégia adotada

### Sistema Seguro

* Necessário analisar mitigar falhas que possam ocorrer
* Melhor disponibilidade
  * Aumentar MTTF
    * Controlo de qualidade de produtos/serviços
  * Diminuir MTTR
    * Dependente do tipo de produto/serviço em causa
  * **Redundância**
    * Total independencia e autonomia de componentes redundantes
    * Calculo MTBF de sistema redundante socorre-se da taxa de falhas por hora dos seus componentes
* Alta disponibilidade
  * Obtenção de disponibilidade de 100% ou próximo
* **Probabilidade de Falha (P)** de um serviço
  * Depende de components
    * Dependem de outros componentes
    * etc
  * Dada pela soma das probabilidades das falhas de todos os fatores
* Mais vulgar uso de **Mean Time Between Failures (MTBF)**
  * É levado em consideração o
    * **Mean time to fail (MTTF)**
    * **Mean time to repair/replace (MTTR)**
      * Cópias de segurança ajudam a retomar imediatamente
      * Só termina quando a operacionabilidade está integralmente recuperada
    * MTBF = MTTF + MTTR
* Disponibilidade de um sistema:
  * Disp = Tempo de operação sem falha / tempo de operação total
    * = MTTF / (MTTF + MTTR)
      * = MTTF / MTBF
* Inverso de MTBF é taxa de falhas por horas
  * Representado por Lambda(λ)
  * Quando calculado para um milhão de horas é designado por FIT
  * MTBF total = 1000 0000 / FIT total
  * FIT total = Soma de todos os FITs

### Fault Avoidance

* Varios mecanismos podem ser utilizados
  * Monitorização
  * Alarmistica
    * Verificacao de utilizacao de recursos
      * Disco
      * CPU
      * Temperatura
      * Humidade
      * Etc

### Nivel de tolerancia(Fault Tolerance)

* Classifica o sistema ou serviço de acordo com o seu comportamento perante uma falha de qualquer origem
  * Se:
    * Mantém o funcionamento : **Full Fault Tolerant**
    * Ocorre degradação temporária : **Gracefull Degradation**
    * Degradação é significativa ou prolongada: **Fail Soft**
    * Torna o sistema/serviço indisponivel mas mantem integridade: **Fail Safe**
* Mesmo com recurso à redundância, podem existir componentes comuns ao sistema redundante, por exemplo:
  * Alimentação elétrica
  * Sistema de controlo de redundância
  * Acesso á internet se só houver um e for necessário para a empresa
  * Componentes partilhados designam-se por **SPOF Single Point of Failure**
    * Devem ser evitados
* Pode existir falhas em componentes não fisicos, por exemplo:
  * vulnerabilidade no sistema operativo
* **CMF Common-Mode Fault** é uma falha que provoca a indisponibilidade de mais do que um componente do sistema redundante
  * SPOF é sempre CMF mas inverso não é verdade
  * CMF implica que falha vários, SPOF implica que falha **TUDO**







