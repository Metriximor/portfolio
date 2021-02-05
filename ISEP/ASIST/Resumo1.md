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

## Gestão de Acessos

* **Network Access Control (NAC)**
  * É um conceito de controlo de acesso a uma infraestrutura pela implementação de políticas de segurança
  * Objetivos
    * Mitigar e/ou prevenir ataques zero-day
    * aplicar politica de segurança ao longo da infraestrutura
    * Uso de identidades para controlo acesso
  * Estes objetivos podem ser alcançados através de vários mecanismos
    * Politicas de segurança
      * Definicao controlo segurança
    * Filtragem
    * Prevenção
    * etc
  * Sistema de deteção e resposta automática
    * Reação em tempo real
    * Impedir ameaças antes de danos
  * Implementação
    * Critério Pré-admissão
      * Sistema cumpre requisitos de segurança antes que consiga comunicar com a rede
        * Atualizações instaladas
        * Antivirus atualizado
        * etc
      * Sistemas
      * Serviços
    * Critério Pós-admissão
      * Permitir ou negar acesso baseado na atividade do utilizado (matriz de autorizações)
        * Com base na atividade do utilizador
        * Numa matriz de autorizações previamente definida
      * Envolve os utilizadores a aceder a rede
  * Identificação Utilizadores
    * Utilizador representa interveniente de uma infraestrutura
    * Autenticação necessária para aceder a infraestrutura
    * Autenticação mais simples: **Password Authentication Protocol (PAP)**
      * Troca 2 mensagens duas mensagens no inicio estabelecimento de autenticação
        1. Utilizador envia Identificação e Senha
        2. Autenticação Valida o par(id/senha)
        3. Devolve a autorização ou negação de acesso
      * É inseguro
        * Uso de texto claro (legível)
        * Não há proteção de repetições ou multiplas falhas
        * Id e Senha precisam estar definidas previamente
      * Código
        * 1 - Request
        * 2 - Ack
        * 3 - Nak
    * Método alternativo mais seguro **Challenge-Handshake Authentication Protocol (CHAP)**
      * Sistema de 3 mensagens
      * Verifica periodicamente a identidade do utilizador
      * Requer definição previa de id e senha
      * Composição
        * Campo código indica operação (8 bits)
        * Campo id é um número aleatorio para mapear os desafios e respostas (8 bits)
        * Campo dados contem: (16+variavel bits)
          * Tamanho do texto de desafio ou resposta (16 bits)
          * Desafio (codigo 1) ou Resposta (Codigo 2) ou Sucesso (Codigo 3) ou Falha (codigo 4)
          * Nome identifica dispositivo que envia desafio
    * Ponto de acesso à rede é designado por **Policy Enforcement Point (PEP)**
      * Que deve realizar 1 destes:
        * Deve conter a identificação e credenciais dos utilizados para validar o acesso
        * Contactar  um **Policy Decision Point (PDP)** que fica com o cargo de validar as credenciais dadas
    * Não é especificamente protocolo mas **Extensible Authentication Protocol (EAP)**
      * na realidade é uma estrutura (framework) para autenticação
      * Permite múltiplos sistemas autenticação
        * Uso cartões
        * biometria
        * etc
      * PEP pass-through
        * Quando conexão é efetuada através de ponto de acesso sem fios
      * PEP transparente e autenticação no PDP
    * Possivel implementar **Protected Extensible Authentication Protocol (PEAP)**
      * Normas **wifi protected access (WPA)** incluem PEAP
      * Encapsula EAP num tunel **Transport Layer Security (TLS)**
* Mecanismos autenticação mais utilizados baseiam-se num segredo partilhado
  * Exemplo: senha de acesso
  * Segredo pré-partilhado
    * Enquadra-se na cifra simétrica
    * Garante a confidencialidade
  * Pode não garantir autenticidade
    * Pois pode ser fraco ou obtido por Engenharia social
  * Segredo pré-partilhado deve ser exclusivo a um par de entidades
    * Para N entidades deve existir Combinações de N dois a dois possiveis chaves
  * Número de segredos elevados conduz a problemas humanos
  * Implica a criação prévia do segredo
    * Por exemplo: Conta do utilizador
  * Logo uma entidade anteriormente desconhecida nunca se pode autenticar
* **Identity Management**
  * Descentralizada / Controlo de Acesso Distribuido
    * Várias entidades ao longo do sistema executem a verificação de acesso
      * Sincronizaçao complexa e elevado esforço administrativo
      * Utilizadores têm a tendencia de usar a mesma senha, anotar as senhas em papel
      * Vantagens no controlo de autorização de acessos
  * Centralizada /  Controlo de Acesso Distribuido
    * Inexistencia de sincronização
    * Menor esforço administrativo
    * Uma única autenticação
    * **Single Sign-On (SSO)**
    * Esforço acrescido de autorização de acessos
    * Especialmente utilizada em organizaçõe
* Serviço de diretório
  * Consiste numa base de dados com informação sobre objetos e entidades
  * Serviços baseados no **Lightweight Directory Access Protocol (LDAP)** RFC 3494
    * Active Directory baseado em LDAP
    * Evolução compativel do protocolo X.500
    * Suporta exportação de ramos da árvore
      * Ou da árvore toda
    * Utiliza TCP como mecanismo transporte
      * Baseia-se na **Abstract Syntax Notation One (ASN.1)**
    * Encapsulado num formato **LDAPMessage**
      * String com
        * Numero sequencia
          * Caso numero seja desconhecido
            * Conexao terminada
            * Devolve-se indicação desconexão com código erro **ProtocolError**
        * Identificador
        * Operação pretendida
        * Mensagem
          * Caso impossibilidade de analize
            * Conexão terminada
            * Pode ou não devolver mensagem
    * RFC 4511
      * Base de dados não relacional que pode alojar autenticações das entidade
      * Estrutura flexivel e otimizada para operações consulta
      * topo estrutura é designado **root**
      * atributos indexados para otimizar pesquisa/consulta
      * cliente acede ao diretorio global através de um cliente ou **Directory User Agent (DUA)**
      * Cliente interage com um ou mais servidores ou **Directory System Agents (DSA)** através de protocolo LDAP
    * RFC 4512
      * Define o schema dos atributos dos objetos LDAP (logo nao é livre)
      * Contém as classes possíveis contendo cada uma os atributos que
        * são válidos
        * que tipo de utilização é permitida em cada um
          * Alguns atributos obrigatorios outros opcionais
      * Classes utilizam o conceito herança
      * Classes podem ser
        * Estruturais
        * Auxiliares
      * Cada objetos pertence a uma classe estrutural
        * Podem pertencer a várias auxiliares
      * Atributos obrigatórios
        * Encontra-se o **Domain Component (DC)**
          * Pode pertencer á classe **dcObject** (auxiliar)
          * Conjugado com a classe estrutural **Organization** ou **Domain**
      * Nomeação baseada no nome de dominio DNS
        * DNS: isep.ipp.pt
        * root: dc=isep,dc=ipp,dc=pt
    * Nome que identifica objeto único na árvore LDAP **Distinguished Name (DN)**
      * DN corresponde ao root é designado **base DN** ou **root DN**
      * DN têm de ser único
      * Nome de atributos podem ser repetidos em ramos diferentes da árvore **Relative Distinguished Names (RDN)**
        * São únicos e exclusivos no ramo em que se encontram
        * Exemplo: uid=1,dc=isep,dc=ipp,dc=pt
  * Processo autenticação
    1. **Identificação**
       * Consiste em anunciar quem é identidade
         * Nome utilizador(ID)
         * Senha de acesso
    2. **Autenticação**
       * Sistema valida o par id senha
       * devolve sucesso ou insucesso
  * Passos efetuados para todos os serviços pretendidos para aceder
  * Autenticacao vs Autorização
    * Autenticação - comprovar a identificação de quem se autentica
    * Autorização - verificar se o ID pode aceder ao serviço
  * Serviço centralizado de autenticação vantajoso (pois permite que todos os serviços validem o utilizador)
    * Designado por **Policy Decision Point (PDP)**
    * Validação da autorização recorre a outro serviço centralizado **Policy Information Point (PIP)**
    * Utilizador acede ao **Policy Enforcement Point (PEP)** que interage com o PDP
      * É normalmente um serviço de rede
      * Ou um tunel vpn
      * Ou um access point
        * Denomina-se **Network Access service** ou **network access server** (NAS)
  * Registo de acessos **Accounting**
    * É necessário para obrigações legais ou controlo interno
    * Regista os acessos concedidos e negados à entidades
  * Junção dos serviços Accounting, Authentication e Authorization denominam-se **AAA - Authentication, Authorization, Accounting**
    * Protocolos para assegurar o suporte AAA
      * **remote Authentication Dial in User Service (RADIUS)** RFC 2865
        * É um protocolo e serviço que assegura as comunicações entre o PEP e PDP
        * Ocorre em UDP
        * Pode ter um PIP e accounting local ou comunicar com outros serviços através de extenções
        * Pedidos registados apenas no inicio e fim da sessao
        * 8 bits para o par atributo - valor (AV)
      * **Terminal Access Controller Access-Control System Plus (TACACS+)**
        * Evolução do TACACS e XTACACAS mas é incompativel com eles
        * Usa TCP
        * Isola verificações
          * Autenticação
          * Autorização
          * Repete a autorização sempre que a execução de um novo comando é requerida
      * **Diameter** RFC 6733
        * Evolução baseada no RADIUS
          * Não compativel
        * Suporta
          * EAP
          * **SCTP (Stream Control Transmission Protocol)**
          * Mecanismos de failover
        * Baseado em TCP
        * 32 bits para definir par atributo-valor **Attribute-Value Pair AVP**
          * Mais escalável (por causa dos 32 bits..)
          * AVP contem informação de
            * autenticação
            * autorização
            * encaminhamento
            * segurança
            * configuração para pedido e resposta
        * Suporta redes
          * cabladas
          * wifi
          * 3g
          * ip multimedia system (IMS)
          * LTE/4G
    * Método para que o AAA suporte ter uma third party a lidar com a identificação e autenticação, através de bilhetes/tickets
      * **Ticket Authentication**
      * Sistema mais comum é **Kerberos**
        * Desenvolvido pelo MIT
        * Versão atual V5 RFC 4120
        * **Single Sign-On(SSO)**
        * Proteção ás credenciais de autenticação
        * Forte Autenticação Aplicações Cliente/Servidor
          * Criptografia de chave secreta
        * RFC 4556 pode socorrer da **Public Key Infrastructure PKI**
        * Entidades a quem distribui chaves designa-se **Principal**
          * Nome de principal possui reservas
            * krbgt é reservado
            * simbolos @ e / são usados para separar nome do principal, do realm e componentes do nome do principal respetivamente
            * Exemplo: *user@realm* e *sftp/server@realm*
        * Divide a infraestrutura em **Realms**
          * Cada realm contem obrigatoriamente
            * Serviço de distribuição de chaves **Key Distribution Center (KDC)**
              * Utilizadores e recursos(principals) estão registados no KDC
              * Uma base de dados das chaves de todos é mantida
              * Executa dois serviços distintos e paralelos
                * **Authentication Service (AS)**
                  * Possui uma chave partilhada com principals
                  * Aceita ou rejeita tentativas de acesso
                  * Fornece aos principals um ticket para provar identidade ao TGS
                * **Ticket Granting Service (TGS)**
                  * Fornece o **Ticket-Granting tickets (TGT)**
                    * Chaves de sessão para comunicação temporárias para principals
                    * Tem tempo de vida
                    * Exige sincronização horária nos principals (ou nega acesso)
                    * Prova que o principal se autenticou no KDC e está autorizado
                * Tickets
                  * São mensagens encriptadas
                  * Provam autorização de acesso a recurso
                  * Se ambos(utilizador e recurso) estão autenticados e o utilizador tem permissao, Kerberos fornece um ticket
                  * Possuem tempo de vida
                  * Parametros de utilização especificos
                    * Expira exige a renovação ou novo ticket
                  * Todos os principals autenticados significa que toda a estrutura está assegurada e autorizada
        * Passos de utilização do Kerberos
          1. Principal liga ao realm e envia pedido autenticação ao KDC
             1. Utilizador insere a autenticação no cliente
             2. Cliente encripta e envia-a ao KDC
             3. KDC verifica autenticação na base de dados do AS
          2. Sendo válido é devolvido um Ticket-Granting Ticket TGT
             1. Gera uma chave simétrica para ser usada na comunicação
             2. Encripta com hash da senha do utilizador
             3. Gera TGT encriptado
             4. Transmite a chave simétrica e o TGT ao cliente
             5. TGT é utilizado até expirar e decifra a chave simétrica com o hash
          3. Quando o principal acede após autenticação a recurso da rede o TGT é utilizado para pedir ticket de acesso a recurso
             1. Cliente envia TGT ao KDC com o pedido de acesso ao recurso
          4. Novo pedido enviado ao KDC e validado
             1. KDC verifica a validade do TGT e a autorização para uasr recurso
             2. KDC gera um ticket de acesso ao recurso e envia-o ao cliente
             3. Cliente envia ticket de acesso ao servidor ou serviço do recurso
             4. O servidor ou serviço valida o ticket de acesso com o KDC
             5. Após verificação de identidade e autorização o Kerberos está concluido
             6. Servidor abre sessão com o cliente e estabelece comunicação
        * Pode gerir relações de confiança entre realms distintos
          * Principal de um realm acede a recursos de um realm distinto sem necessitar de possuir credenciais no AS doutro realm
          * Para isto define-se o TGS do realm como um principal no realm exterior
          * Um Realm pode comunicar com outro Realm se ambos partilharem uma chave inter-realm
            * Será usada para encriptar tickets de pedido de acesso a recursos do realm remoto
        * Suporta hierarquia entre realms
          * Exemplo: Dominios Active Directory da Microsoft na mesma tree
          * Relação de confiança é transitiva
            * Realm A confia no Realm B, Realm B confia no C entao o A confia no C
        * Desvantagens
          * KDC é um SPOF
          * Chaves com base nas senhas dos utilizadores
            * Senha raca potencia a captura e posterior acesso á chave
          * Não disponibiliza mecanismos de tolerância a falhas
            * Razoavel configurar mais que um KDC no mesmo realm
              * Sincronização tem de ser feita com sistemas externos
              * Aplicações devem estar preparadas com base em tentativa erro
                * KDC principal nao responde deve tentar o alternativo ate percorrer todos os KDC
                  * Funcionalidade Active Directory
          * Se o KDC principal inoperacional, impossibilita administração do kerberos








