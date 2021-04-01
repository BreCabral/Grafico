#pragma once

namespace Grafico {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para FormPrincipal
	/// </summary>
	public ref class FormPrincipal : public System::Windows::Forms::Form
	{
	public:
		FormPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~FormPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btAdicionar;
	private: System::Windows::Forms::TextBox^ tbCidade;
	private: System::Windows::Forms::TextBox^ tbPopulacao;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ graficoPopulacao;


	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btAdicionar = (gcnew System::Windows::Forms::Button());
			this->tbCidade = (gcnew System::Windows::Forms::TextBox());
			this->tbPopulacao = (gcnew System::Windows::Forms::TextBox());
			this->graficoPopulacao = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graficoPopulacao))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Cidade";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(137, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"População";
			// 
			// btAdicionar
			// 
			this->btAdicionar->Location = System::Drawing::Point(283, 29);
			this->btAdicionar->Name = L"btAdicionar";
			this->btAdicionar->Size = System::Drawing::Size(75, 23);
			this->btAdicionar->TabIndex = 2;
			this->btAdicionar->Text = L"Adicionar";
			this->btAdicionar->UseVisualStyleBackColor = true;
			this->btAdicionar->Click += gcnew System::EventHandler(this, &FormPrincipal::btAdicionar_Click);
			// 
			// tbCidade
			// 
			this->tbCidade->Location = System::Drawing::Point(12, 29);
			this->tbCidade->Name = L"tbCidade";
			this->tbCidade->Size = System::Drawing::Size(100, 20);
			this->tbCidade->TabIndex = 3;
			// 
			// tbPopulacao
			// 
			this->tbPopulacao->Location = System::Drawing::Point(140, 29);
			this->tbPopulacao->Name = L"tbPopulacao";
			this->tbPopulacao->Size = System::Drawing::Size(100, 20);
			this->tbPopulacao->TabIndex = 4;
			// 
			// graficoPopulacao
			// 
			chartArea1->Name = L"ChartArea1";
			this->graficoPopulacao->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->graficoPopulacao->Legends->Add(legend1);
			this->graficoPopulacao->Location = System::Drawing::Point(12, 62);
			this->graficoPopulacao->Name = L"graficoPopulacao";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"População";
			this->graficoPopulacao->Series->Add(series1);
			this->graficoPopulacao->Size = System::Drawing::Size(559, 300);
			this->graficoPopulacao->TabIndex = 5;
			this->graficoPopulacao->Text = L"chart1";
			// 
			// FormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(583, 374);
			this->Controls->Add(this->graficoPopulacao);
			this->Controls->Add(this->tbPopulacao);
			this->Controls->Add(this->tbCidade);
			this->Controls->Add(this->btAdicionar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"FormPrincipal";
			this->Text = L"Graficos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graficoPopulacao))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btAdicionar_Click(System::Object^ sender, System::EventArgs^ e) {
		int populacao;
		String^ cidade = tbCidade->Text;
		try
		{
			populacao = Convert::ToInt32(tbPopulacao->Text);
		}
		catch (...)
		{
			MessageBox::Show("Numero Invalido", "ERRO");
			return;
		}
		graficoPopulacao->Series["População"]->Points->AddXY(cidade, populacao);
		Refresh();
	}
};
}
