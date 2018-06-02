namespace MyProject
{
    partial class addmed
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.add = new System.Windows.Forms.Button();
            this.se = new System.Windows.Forms.TextBox();
            this.desc = new System.Windows.Forms.TextBox();
            this.ed = new System.Windows.Forms.TextBox();
            this.qua = new System.Windows.Forms.TextBox();
            this.mname = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // add
            // 
            this.add.Font = new System.Drawing.Font("Microsoft Sans Serif", 26.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.add.Location = new System.Drawing.Point(518, 315);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(203, 74);
            this.add.TabIndex = 50;
            this.add.Text = "ADD";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // se
            // 
            this.se.Location = new System.Drawing.Point(254, 133);
            this.se.Name = "se";
            this.se.Size = new System.Drawing.Size(140, 20);
            this.se.TabIndex = 48;
            // 
            // desc
            // 
            this.desc.Location = new System.Drawing.Point(254, 86);
            this.desc.Name = "desc";
            this.desc.Size = new System.Drawing.Size(140, 20);
            this.desc.TabIndex = 47;
            // 
            // ed
            // 
            this.ed.Location = new System.Drawing.Point(254, 186);
            this.ed.Name = "ed";
            this.ed.Size = new System.Drawing.Size(140, 20);
            this.ed.TabIndex = 46;
            // 
            // qua
            // 
            this.qua.Location = new System.Drawing.Point(254, 242);
            this.qua.Name = "qua";
            this.qua.Size = new System.Drawing.Size(140, 20);
            this.qua.TabIndex = 45;
            this.qua.TextChanged += new System.EventHandler(this.qua_TextChanged);
            // 
            // mname
            // 
            this.mname.Location = new System.Drawing.Point(254, 42);
            this.mname.Name = "mname";
            this.mname.Size = new System.Drawing.Size(140, 20);
            this.mname.TabIndex = 44;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Arial", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(59, 179);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(135, 27);
            this.label5.TabIndex = 42;
            this.label5.Text = "Expiry Date";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Arial", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(62, 235);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(103, 27);
            this.label4.TabIndex = 41;
            this.label4.Text = "Quantity";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Arial", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(62, 133);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(141, 27);
            this.label3.TabIndex = 40;
            this.label3.Text = "Side Effects";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Arial", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(62, 86);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(132, 27);
            this.label2.TabIndex = 39;
            this.label2.Text = "Description";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(62, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(72, 27);
            this.label1.TabIndex = 38;
            this.label1.Text = "name";
            // 
            // addmed
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(880, 497);
            this.Controls.Add(this.add);
            this.Controls.Add(this.se);
            this.Controls.Add(this.desc);
            this.Controls.Add(this.ed);
            this.Controls.Add(this.qua);
            this.Controls.Add(this.mname);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "addmed";
            this.Text = "addmed";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button add;
        private System.Windows.Forms.TextBox se;
        private System.Windows.Forms.TextBox desc;
        private System.Windows.Forms.TextBox ed;
        private System.Windows.Forms.TextBox qua;
        private System.Windows.Forms.TextBox mname;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}