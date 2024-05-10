/*!
 * \file
 * \brief Class module::Decoder_FRS.
 */
#ifndef DECODER_FRS
#define DECODER_FRS

#include <vector>

#include "Tools/Code/RS/RS_polynomial_generator.hpp"
#include "Module/Decoder/RS/Decoder_RS.hpp"

 /* source : http://www.eccpage.com/  */

namespace aff3ct
{
	namespace module
	{

		template <typename B = int, typename R = float>
		class Decoder_FRS : public Decoder_RS<B, R>
		{
		public:
			using typename Decoder_RS<B, R>::S; // symbol to represent data

		private:
			const int t2;

			std::vector<std::vector<int>> elp;
			std::vector<int> discrepancy;
			std::vector<int> l;
			std::vector<int> u_lu;
			std::vector<int> s;
			std::vector<int> loc;
			std::vector<int> root;
			std::vector<int> reg;
			std::vector<int> z;
			std::vector<int> err;

		public:
			Decoder_FRS(const int& K, const int& N, const tools::RS_polynomial_generator& GF);
			virtual ~Decoder_FRS() = default;
			virtual Decoder_FRS<B, R>* clone() const;

		protected:
			virtual int _decode(S* Y_N, const size_t frame_id);
		};

	}
}

#endif /* DECODER_FRS */